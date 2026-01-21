-- ==========================================
-- MODULE 1: STUDY & PROTOCOL MANAGEMENT
-- ==========================================

-- Master trial registry
CREATE TABLE clinical_trials (
    trial_id SERIAL PRIMARY KEY,
    trial_nct_id VARCHAR(20) UNIQUE NOT NULL, -- e.g., NCT01234567
    trial_title TEXT NOT NULL,
    trial_phase VARCHAR(20) CHECK (trial_phase IN ('Phase I', 'Phase II', 'Phase III', 'Phase IV')),
    therapeutic_area VARCHAR(100) NOT NULL,
    trial_status VARCHAR(50) DEFAULT 'Design' 
        CHECK (trial_status IN ('Design', 'Recruiting', 'Active', 'Completed', 'Suspended', 'Terminated')),
    start_date DATE,
    estimated_completion_date DATE,
    target_enrollment INTEGER CHECK (target_enrollment > 0),
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Protocol versions and documents
CREATE TABLE study_protocols (
    protocol_id SERIAL PRIMARY KEY,
    trial_id INTEGER NOT NULL REFERENCES clinical_trials(trial_id) ON DELETE CASCADE,
    version_number VARCHAR(20) NOT NULL, -- e.g., v1.0, v2.0
    protocol_document JSONB NOT NULL,
    approval_date DATE NOT NULL,
    approved_by_user_id INTEGER, -- FK to users, set later
    electronic_signature TEXT NOT NULL,
    amendment_number INTEGER DEFAULT 0,
    valid_from DATE NOT NULL DEFAULT CURRENT_DATE,
    valid_to DATE,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    UNIQUE(trial_id, version_number)
);

-- Trial sites (hospitals/clinics)
CREATE TABLE study_sites (
    site_id SERIAL PRIMARY KEY,
    trial_id INTEGER NOT NULL REFERENCES clinical_trials(trial_id) ON DELETE CASCADE,
    institution_name VARCHAR(255) NOT NULL,
    country VARCHAR(100) NOT NULL,
    site_status VARCHAR(50) DEFAULT 'Pending' 
        CHECK (site_status IN ('Pending', 'Active', 'Closed', 'Suspended')),
    target_enrollment INTEGER CHECK (target_enrollment >= 0),
    current_enrollment INTEGER DEFAULT 0 CHECK (current_enrollment >= 0),
    site_initiation_date DATE DEFAULT CURRENT_DATE,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Eligibility criteria for trials
CREATE TABLE eligibility_criteria (
    criterion_id SERIAL PRIMARY KEY,
    trial_id INTEGER NOT NULL REFERENCES clinical_trials(trial_id) ON DELETE CASCADE,
    criterion_type VARCHAR(20) NOT NULL CHECK (criterion_type IN ('Inclusion', 'Exclusion')),
    criterion_text TEXT NOT NULL,
    is_mandatory BOOLEAN DEFAULT TRUE,
    criterion_logic VARCHAR(255), -- For automated checking
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- ==========================================
-- MODULE 2: PATIENT MANAGEMENT
-- ==========================================

-- Patient registry
CREATE TABLE patients (
    patient_id SERIAL PRIMARY KEY,
    trial_patient_id VARCHAR(50) UNIQUE NOT NULL, -- e.g., PT-00123
    site_id INTEGER NOT NULL REFERENCES study_sites(site_id) ON DELETE RESTRICT,
    screening_number VARCHAR(50), -- e.g., SCR-1001 (auto-generated)
    patient_status VARCHAR(50) DEFAULT 'Screened' 
        CHECK (patient_status IN ('Screened', 'Enrolled', 'Active', 'Completed', 'Withdrawn', 'Screen Failure')),
    date_of_birth DATE NOT NULL,
    gender VARCHAR(20),
    enrollment_date DATE,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Normalized medical history (instead of JSONB in patients)
CREATE TABLE patient_medical_history (
    history_id SERIAL PRIMARY KEY,
    patient_id INTEGER NOT NULL REFERENCES patients(patient_id) ON DELETE CASCADE,
    condition_code VARCHAR(50), -- ICD-10 code
    condition_name VARCHAR(100) NOT NULL,
    diagnosis_date DATE,
    severity VARCHAR(20),
    is_active BOOLEAN DEFAULT TRUE,
    notes TEXT,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Patient screening results
CREATE TABLE patient_screening (
    screening_id SERIAL PRIMARY KEY,
    patient_id INTEGER NOT NULL REFERENCES patients(patient_id) ON DELETE CASCADE,
    screening_date DATE DEFAULT CURRENT_DATE,
    screening_status VARCHAR(50) DEFAULT 'Pending Review' 
        CHECK (screening_status IN ('Passed', 'Failed', 'Pending Review')),
    eligibility_score INTEGER CHECK (eligibility_score >= 0),
    manual_override BOOLEAN DEFAULT FALSE,
    override_reason TEXT,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Junction table for screening failures (better than JSONB)
CREATE TABLE screening_failures (
    screening_id INTEGER NOT NULL REFERENCES patient_screening(screening_id) ON DELETE CASCADE,
    criterion_id INTEGER NOT NULL REFERENCES eligibility_criteria(criterion_id) ON DELETE CASCADE,
    failure_reason TEXT,
    override_approved BOOLEAN DEFAULT FALSE,
    override_by_user_id INTEGER, -- FK to users, set later
    PRIMARY KEY (screening_id, criterion_id)
);

-- Informed consent records
CREATE TABLE informed_consent (
    consent_id SERIAL PRIMARY KEY,
    patient_id INTEGER UNIQUE NOT NULL REFERENCES patients(patient_id) ON DELETE CASCADE,
    consent_version VARCHAR(20) NOT NULL,
    consent_date DATE NOT NULL DEFAULT CURRENT_DATE,
    digital_signature_hash TEXT NOT NULL,
    is_withdrawn BOOLEAN DEFAULT FALSE,
    withdrawal_date DATE,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    CONSTRAINT withdrawal_after_consent CHECK (withdrawal_date IS NULL OR withdrawal_date >= consent_date)
);

-- Treatment arms (drug vs placebo groups)
CREATE TABLE treatment_arms (
    arm_id SERIAL PRIMARY KEY,
    trial_id INTEGER NOT NULL REFERENCES clinical_trials(trial_id) ON DELETE CASCADE,
    arm_code VARCHAR(20) NOT NULL, -- e.g., ARM-A, PLACEBO
    arm_description TEXT NOT NULL,
    treatment_description JSONB, -- Dosage, frequency, administration details
    allocation_ratio VARCHAR(20) DEFAULT '1:1',
    blinding_level VARCHAR(50) DEFAULT 'Double Blind' 
        CHECK (blinding_level IN ('Open Label', 'Single Blind', 'Double Blind')),
    UNIQUE(trial_id, arm_code)
);

-- Randomization assignments
CREATE TABLE randomization_assignments (
    assignment_id SERIAL PRIMARY KEY,
    patient_id INTEGER UNIQUE NOT NULL REFERENCES patients(patient_id) ON DELETE CASCADE,
    arm_id INTEGER NOT NULL REFERENCES treatment_arms(arm_id) ON DELETE RESTRICT,
    randomization_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    randomization_method VARCHAR(50) 
        CHECK (randomization_method IN ('Simple', 'Block', 'Stratified')),
    stratification_profile JSONB, -- Factors used for stratified randomization
    unblinding_date DATE,
    random_seed VARCHAR(100) NOT NULL, -- For reproducibility
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Stratification factors for randomization
CREATE TABLE stratification_factors (
    factor_id SERIAL PRIMARY KEY,
    trial_id INTEGER NOT NULL REFERENCES clinical_trials(trial_id) ON DELETE CASCADE,
    factor_name VARCHAR(100) NOT NULL, -- e.g., 'Age Group', 'Gender', 'Disease Severity'
    factor_levels JSONB NOT NULL, -- e.g., ['<18', '18-65', '>65']
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- ==========================================
-- MODULE 3: VISITS & DATA COLLECTION
-- ==========================================

-- Visit schedule templates
CREATE TABLE visit_schedules (
    visit_id SERIAL PRIMARY KEY,
    trial_id INTEGER NOT NULL REFERENCES clinical_trials(trial_id) ON DELETE CASCADE,
    visit_number INTEGER NOT NULL,
    visit_name VARCHAR(100) NOT NULL, -- e.g., 'Baseline', 'Week 4', 'Month 6'
    visit_window_before_days INTEGER DEFAULT 0,
    visit_window_after_days INTEGER DEFAULT 0,
    day_offset INTEGER NOT NULL, -- Days from randomization/screening
    required_procedures JSONB, -- Tests required at this visit
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Actual patient visits
CREATE TABLE patient_visits (
    visit_instance_id SERIAL PRIMARY KEY,
    patient_id INTEGER NOT NULL REFERENCES patients(patient_id) ON DELETE CASCADE,
    visit_id INTEGER NOT NULL REFERENCES visit_schedules(visit_id) ON DELETE CASCADE,
    scheduled_date DATE NOT NULL,
    actual_visit_date DATE,
    visit_status VARCHAR(50) DEFAULT 'Scheduled' 
        CHECK (visit_status IN ('Scheduled', 'Completed', 'Missed', 'Cancelled')),
    visit_window_status VARCHAR(50) 
        CHECK (visit_window_status IN ('Within Window', 'Early', 'Late', 'Outside Window')),
    data_queries_count INTEGER DEFAULT 0,
    days_delayed INTEGER GENERATED ALWAYS AS (
        CASE WHEN actual_visit_date IS NOT NULL AND scheduled_date IS NOT NULL 
             THEN (actual_visit_date - scheduled_date) 
             ELSE NULL 
        END
    ) STORED,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    UNIQUE(patient_id, visit_id) -- One patient can't have same visit twice
);

-- eCRF definitions (form templates)
CREATE TABLE ecrf_definitions (
    ecrf_id SERIAL PRIMARY KEY,
    trial_id INTEGER NOT NULL REFERENCES clinical_trials(trial_id) ON DELETE CASCADE,
    ecrf_name VARCHAR(100) NOT NULL, -- e.g., 'Vital Signs', 'Physical Exam'
    ecrf_schema JSONB NOT NULL, -- Form structure
    validation_rules JSONB, -- Data validation logic
    signature_required BOOLEAN DEFAULT TRUE,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- eCRF data (actual form submissions)
CREATE TABLE ecrf_data (
    ecrf_instance_id SERIAL PRIMARY KEY,
    ecrf_id INTEGER NOT NULL REFERENCES ecrf_definitions(ecrf_id) ON DELETE CASCADE,
    patient_id INTEGER NOT NULL REFERENCES patients(patient_id) ON DELETE CASCADE,
    visit_instance_id INTEGER NOT NULL REFERENCES patient_visits(visit_instance_id) ON DELETE CASCADE,
    entered_by_user_id INTEGER, -- FK to users, set later
    form_status VARCHAR(50) DEFAULT 'In Progress' 
        CHECK (form_status IN ('In Progress', 'Completed', 'Signed', 'Locked')),
    form_data JSONB NOT NULL,
    data_entry_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    investigator_signature JSONB,
    query_count INTEGER DEFAULT 0,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- ==========================================
-- MODULE 4: LABORATORY & CLINICAL DATA
-- ==========================================

-- Laboratory test catalog
CREATE TABLE laboratory_tests (
    test_id SERIAL PRIMARY KEY,
    test_name VARCHAR(100) NOT NULL,
    test_code_loinc VARCHAR(50) UNIQUE, -- Standard LOINC code
    unit_of_measure VARCHAR(20),
    reference_ranges JSONB, -- Age/gender-specific normal ranges
    critical_low_value NUMERIC,
    critical_high_value NUMERIC,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Laboratory results
CREATE TABLE lab_results (
    result_id SERIAL PRIMARY KEY,
    patient_id INTEGER NOT NULL REFERENCES patients(patient_id) ON DELETE CASCADE,
    test_id INTEGER NOT NULL REFERENCES laboratory_tests(test_id) ON DELETE CASCADE,
    visit_instance_id INTEGER NOT NULL REFERENCES patient_visits(visit_instance_id) ON DELETE CASCADE,
    result_value NUMERIC NOT NULL,
    result_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    result_status VARCHAR(50) DEFAULT 'Pending' 
        CHECK (result_status IN ('Pending', 'Completed', 'Critical', 'Cancelled')),
    critical_result_flag CHAR(1) DEFAULT 'N' CHECK (critical_result_flag IN ('Y', 'N')),
    reference_low NUMERIC,
    reference_high NUMERIC,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    INDEX idx_critical_labs (critical_result_flag, result_date)
);

-- Vital signs measurements
CREATE TABLE vital_signs (
    vital_id SERIAL PRIMARY KEY,
    patient_id INTEGER NOT NULL REFERENCES patients(patient_id) ON DELETE CASCADE,
    visit_instance_id INTEGER NOT NULL REFERENCES patient_visits(visit_instance_id) ON DELETE CASCADE,
    measurement_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    systolic_bp INTEGER NOT NULL CHECK (systolic_bp BETWEEN 50 AND 250),
    diastolic_bp INTEGER NOT NULL CHECK (diastolic_bp BETWEEN 30 AND 150),
    heart_rate INTEGER CHECK (heart_rate BETWEEN 30 AND 250),
    temperature NUMERIC(3,1) CHECK (temperature BETWEEN 30 AND 45),
    oxygen_saturation INTEGER CHECK (oxygen_saturation BETWEEN 0 AND 100),
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Medical imaging records
CREATE TABLE medical_images (
    image_id SERIAL PRIMARY KEY,
    patient_id INTEGER NOT NULL REFERENCES patients(patient_id) ON DELETE CASCADE,
    visit_instance_id INTEGER NOT NULL REFERENCES patient_visits(visit_instance_id) ON DELETE CASCADE,
    image_type VARCHAR(50) NOT NULL 
        CHECK (image_type IN ('X-ray', 'MRI', 'CT', 'Ultrasound', 'PET', 'Mammogram')),
    image_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    imaging_protocol TEXT,
    file_path TEXT NOT NULL, -- Cloud storage path (S3, etc.)
    radiologist_review JSONB,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- ==========================================
-- MODULE 5: SAFETY MONITORING
-- ==========================================

-- Adverse events
CREATE TABLE adverse_events (
    ae_id SERIAL PRIMARY KEY,
    patient_id INTEGER NOT NULL REFERENCES patients(patient_id) ON DELETE CASCADE,
    visit_instance_id INTEGER REFERENCES patient_visits(visit_instance_id) ON DELETE SET NULL,
    ae_term VARCHAR(255) NOT NULL,
    ae_start_date DATE NOT NULL,
    ae_end_date DATE,
    severity_grade INTEGER NOT NULL CHECK (severity_grade BETWEEN 1 AND 5),
    causality_relationship VARCHAR(50) 
        CHECK (causality_relationship IN ('Definite', 'Probable', 'Possible', 'Unlikely', 'Unrelated')),
    treatment_related BOOLEAN,
    results_in_death BOOLEAN DEFAULT FALSE,
    life_threatening BOOLEAN DEFAULT FALSE,
    requires_hospitalization BOOLEAN DEFAULT FALSE,
    ae_description TEXT,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    CONSTRAINT ae_dates_valid CHECK (ae_end_date IS NULL OR ae_end_date >= ae_start_date)
);

-- Serious adverse events (SAEs)
CREATE TABLE serious_adverse_events (
    sae_id SERIAL PRIMARY KEY,
    ae_id INTEGER UNIQUE NOT NULL REFERENCES adverse_events(ae_id) ON DELETE CASCADE,
    sae_report_number VARCHAR(100) UNIQUE,
    regulatory_body VARCHAR(50) DEFAULT 'FDA',
    report_deadline_date DATE NOT NULL,
    report_submitted_date DATE,
    dsmb_review_date DATE,
    sae_status VARCHAR(50) DEFAULT 'Open' 
        CHECK (sae_status IN ('Open', 'Under Investigation', 'Closed', 'Reported')),
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    CONSTRAINT submission_before_deadline CHECK (
        report_submitted_date IS NULL OR report_submitted_date <= report_deadline_date
    )
);

-- Protocol deviations
CREATE TABLE protocol_deviations (
    deviation_id SERIAL PRIMARY KEY,
    patient_id INTEGER NOT NULL REFERENCES patients(patient_id) ON DELETE CASCADE,
    visit_instance_id INTEGER REFERENCES patient_visits(visit_instance_id) ON DELETE SET NULL,
    deviation_type VARCHAR(50) NOT NULL 
        CHECK (deviation_type IN ('Minor', 'Major', 'Critical')),
    deviation_date DATE NOT NULL DEFAULT CURRENT_DATE,
    description TEXT NOT NULL,
    corrective_action TEXT,
    reported_to_irb BOOLEAN DEFAULT FALSE,
    reported_by_user_id INTEGER, -- FK to users, set later
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Safety alerts system (IMPROVED with polymorphic FK)
CREATE TABLE safety_alerts (
    alert_id SERIAL PRIMARY KEY,
    patient_id INTEGER NOT NULL REFERENCES patients(patient_id) ON DELETE CASCADE,
    
    -- Source of the alert (polymorphic foreign key)
    source_type VARCHAR(50) NOT NULL 
        CHECK (source_type IN ('LAB_RESULT', 'VITAL_SIGN', 'ADVERSE_EVENT', 'PROTOCOL_DEVIATION', 'OTHER')),
    source_table VARCHAR(50) NOT NULL,
    source_record_id INTEGER NOT NULL,
    
    -- Visit context (optional - AEs can happen between visits)
    visit_instance_id INTEGER REFERENCES patient_visits(visit_instance_id) ON DELETE SET NULL,
    
    -- Alert details
    alert_code VARCHAR(20) NOT NULL, -- e.g., 'CRITICAL_LAB', 'ABNORMAL_VITAL', 'SAE', etc.
    alert_message TEXT NOT NULL,
    alert_severity VARCHAR(20) DEFAULT 'INFO' 
        CHECK (alert_severity IN ('INFO', 'WARNING', 'CRITICAL', 'SEVERE')),
    alert_status VARCHAR(20) DEFAULT 'ACTIVE' 
        CHECK (alert_status IN ('ACTIVE', 'ACKNOWLEDGED', 'RESOLVED', 'ESCALATED', 'DISMISSED')),
    acknowledged_by_user_id INTEGER, -- FK to users, set later
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    escalated_at TIMESTAMP,
    escalation_level INTEGER DEFAULT 1 CHECK (escalation_level BETWEEN 1 AND 5),
    
    -- Trigger details (for lab/vital alerts)
    measured_value NUMERIC,
    reference_range_low NUMERIC,
    reference_range_high NUMERIC,
    threshold_exceeded_percent NUMERIC,
    
    INDEX idx_alert_status (alert_status, created_at),
    INDEX idx_patient_alerts (patient_id, alert_status)
);

-- Data Safety Monitoring Board meetings
CREATE TABLE dsmb_meetings (
    meeting_id SERIAL PRIMARY KEY,
    trial_id INTEGER NOT NULL REFERENCES clinical_trials(trial_id) ON DELETE CASCADE,
    meeting_date DATE NOT NULL,
    meeting_type VARCHAR(50) DEFAULT 'Scheduled' 
        CHECK (meeting_type IN ('Scheduled', 'Emergency', 'Ad-hoc')),
    data_cutoff_date DATE NOT NULL,
    recommendation VARCHAR(100) 
        CHECK (recommendation IN ('Continue', 'Modify', 'Stop', 'Requires Follow-up')),
    meeting_minutes JSONB,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- ==========================================
-- MODULE 6: STATISTICAL ANALYSIS
-- ==========================================

-- Analysis datasets (frozen data snapshots)
CREATE TABLE analysis_datasets (
    dataset_id SERIAL PRIMARY KEY,
    trial_id INTEGER NOT NULL REFERENCES clinical_trials(trial_id) ON DELETE CASCADE,
    dataset_name VARCHAR(100) NOT NULL, -- e.g., 'Safety Analysis Set', 'Full Analysis Set'
    dataset_type VARCHAR(50) NOT NULL 
        CHECK (dataset_type IN ('Safety', 'Efficacy', 'ITT', 'Per Protocol', 'Exploratory')),
    snapshot_date DATE DEFAULT CURRENT_DATE,
    data_cutoff_date DATE NOT NULL,
    population_count INTEGER CHECK (population_count >= 0),
    analysis_results JSONB,
    p_value NUMERIC,
    statistical_significance BOOLEAN,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Survival analysis results
CREATE TABLE survival_analysis (
    analysis_id SERIAL PRIMARY KEY,
    trial_id INTEGER NOT NULL REFERENCES clinical_trials(trial_id) ON DELETE CASCADE,
    endpoint_type VARCHAR(100) NOT NULL, -- e.g., 'Overall Survival', 'Progression-Free Survival'
    time_points JSONB NOT NULL, -- Array of time points
    survival_probabilities JSONB NOT NULL, -- Kaplan-Meier probabilities
    hazard_ratio NUMERIC,
    logrank_p_value NUMERIC,
    confidence_interval_95 VARCHAR(50), -- e.g., '0.65-0.89'
    calculated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Data locks for analysis integrity
CREATE TABLE data_locks (
    lock_id SERIAL PRIMARY KEY,
    trial_id INTEGER NOT NULL REFERENCES clinical_trials(trial_id) ON DELETE CASCADE,
    lock_type VARCHAR(50) NOT NULL 
        CHECK (lock_type IN ('Interim', 'Final', 'Database', 'Partial')),
    lock_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    locked_by_user_id INTEGER, -- FK to users, set later
    unlock_date TIMESTAMP,
    snapshot_hash TEXT NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- ==========================================
-- MODULE 7: REGULATORY & AUDIT
-- ==========================================

-- 21 CFR Part 11 compliant audit trail
CREATE TABLE audit_trail_21cfr (
    audit_id SERIAL PRIMARY KEY,
    table_name VARCHAR(50) NOT NULL,
    record_id INTEGER NOT NULL,
    column_name VARCHAR(50),
    action_type VARCHAR(10) NOT NULL CHECK (action_type IN ('INSERT', 'UPDATE', 'DELETE')),
    old_value JSONB,
    new_value JSONB,
    changed_by_user_id INTEGER, -- FK to users, set later
    change_timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    change_reason TEXT NOT NULL,
    ip_address VARCHAR(45),
    data_hash TEXT NOT NULL, -- Cryptographic hash of this entry
    INDEX idx_audit_table (table_name, record_id, change_timestamp)
);

-- Electronic signatures
CREATE TABLE electronic_signatures (
    signature_id SERIAL PRIMARY KEY,
    signatory_user_id INTEGER, -- FK to users, set later
    document_type VARCHAR(50) NOT NULL 
        CHECK (document_type IN ('Protocol', 'eCRF', 'Consent', 'SAE Report', 'Deviation Report')),
    document_id INTEGER NOT NULL, -- Reference to the signed document
    signature_hash TEXT NOT NULL,
    signing_reason TEXT NOT NULL,
    signed_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    INDEX idx_signature_doc (document_type, document_id)
);

-- Data quality queries
CREATE TABLE data_queries (
    query_id SERIAL PRIMARY KEY,
    ecrf_instance_id INTEGER NOT NULL REFERENCES ecrf_data(ecrf_instance_id) ON DELETE CASCADE,
    field_name VARCHAR(100) NOT NULL,
    query_text TEXT NOT NULL,
    query_status VARCHAR(20) DEFAULT 'Open' 
        CHECK (query_status IN ('Open', 'Answered', 'Resolved', 'Closed')),
    raised_by_user_id INTEGER, -- FK to users, set later
    raised_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    response_text TEXT,
    resolved_by_user_id INTEGER, -- FK to users, set later
    resolved_date TIMESTAMP,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    CONSTRAINT resolution_date_valid CHECK (
        resolved_date IS NULL OR resolved_date >= raised_date
    )
);

-- User access logging
CREATE TABLE user_access_log (
    log_id SERIAL PRIMARY KEY,
    user_id INTEGER, -- FK to users, set later
    accessed_table VARCHAR(50) NOT NULL,
    accessed_record_id INTEGER,
    access_type VARCHAR(20) NOT NULL 
        CHECK (access_type IN ('VIEW', 'EDIT', 'DELETE', 'EXPORT', 'SIGN')),
    access_timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    ip_address VARCHAR(45),
    user_agent TEXT,
    session_id VARCHAR(100),
    INDEX idx_access_user (user_id, access_timestamp),
    INDEX idx_access_table (accessed_table, accessed_record_id)
);

-- Site performance metrics
CREATE TABLE site_performance (
    performance_id SERIAL PRIMARY KEY,
    site_id INTEGER NOT NULL REFERENCES study_sites(site_id) ON DELETE CASCADE,
    period_start_date DATE NOT NULL,
    period_end_date DATE NOT NULL,
    patients_screened INTEGER DEFAULT 0,
    patients_enrolled INTEGER DEFAULT 0,
    screen_fail_rate DECIMAL(5,2),
    average_screening_days DECIMAL(5,2),
    protocol_deviations_count INTEGER DEFAULT 0,
    query_resolution_days_avg DECIMAL(5,2),
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    CONSTRAINT valid_period CHECK (period_end_date > period_start_date)
);

-- ==========================================
-- MODULE 8: USERS & SECURITY
-- ==========================================

-- User accounts and authentication
CREATE TABLE users (
    user_id SERIAL PRIMARY KEY,
    username VARCHAR(50) UNIQUE NOT NULL,
    password_hash TEXT NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL,
    role VARCHAR(50) NOT NULL 
        CHECK (role IN ('PI', 'Sub-Investigator', 'Coordinator', 'Safety_Monitor', 
                       'Data_Manager', 'Statistician', 'Admin', 'Auditor', 'Monitor')),
    site_id INTEGER REFERENCES study_sites(site_id) ON DELETE SET NULL,
    is_active BOOLEAN DEFAULT TRUE,
    mfa_enabled BOOLEAN DEFAULT FALSE,
    mfa_secret VARCHAR(100),
    last_login TIMESTAMP,
    password_reset_token VARCHAR(100),
    password_reset_expires TIMESTAMP,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    CONSTRAINT site_role_check CHECK (
        (role IN ('PI', 'Sub-Investigator', 'Coordinator') AND site_id IS NOT NULL) OR
        (role IN ('Safety_Monitor', 'Data_Manager', 'Statistician', 'Admin', 'Auditor', 'Monitor') AND site_id IS NULL)
    )
);

-- Investigators (linked to users)
CREATE TABLE investigators (
    investigator_id SERIAL PRIMARY KEY,
    user_id INTEGER UNIQUE REFERENCES users(user_id) ON DELETE CASCADE,
    site_id INTEGER NOT NULL REFERENCES study_sites(site_id) ON DELETE CASCADE,
    investigator_name VARCHAR(255) NOT NULL,
    medical_license_number VARCHAR(100) UNIQUE,
    gcp_certification_date DATE NOT NULL,
    electronic_signature_key TEXT NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- ==========================================
-- ADD FOREIGN KEYS THAT DEPEND ON USERS TABLE
-- ==========================================

ALTER TABLE study_protocols 
ADD CONSTRAINT fk_protocol_approved_by 
FOREIGN KEY (approved_by_user_id) REFERENCES users(user_id) ON DELETE SET NULL;

ALTER TABLE screening_failures 
ADD CONSTRAINT fk_failure_override_by 
FOREIGN KEY (override_by_user_id) REFERENCES users(user_id) ON DELETE SET NULL;

ALTER TABLE ecrf_data 
ADD CONSTRAINT fk_ecrf_entered_by 
FOREIGN KEY (entered_by_user_id) REFERENCES users(user_id) ON DELETE SET NULL;

ALTER TABLE safety_alerts 
ADD CONSTRAINT fk_alert_acknowledged_by 
FOREIGN KEY (acknowledged_by_user_id) REFERENCES users(user_id) ON DELETE SET NULL;

ALTER TABLE protocol_deviations 
ADD CONSTRAINT fk_deviation_reported_by 
FOREIGN KEY (reported_by_user_id) REFERENCES users(user_id) ON DELETE SET NULL;

ALTER TABLE data_locks 
ADD CONSTRAINT fk_lock_locked_by 
FOREIGN KEY (locked_by_user_id) REFERENCES users(user_id) ON DELETE SET NULL;

ALTER TABLE audit_trail_21cfr 
ADD CONSTRAINT fk_audit_changed_by 
FOREIGN KEY (changed_by_user_id) REFERENCES users(user_id) ON DELETE SET NULL;

ALTER TABLE electronic_signatures 
ADD CONSTRAINT fk_signature_signatory 
FOREIGN KEY (signatory_user_id) REFERENCES users(user_id) ON DELETE SET NULL;

ALTER TABLE data_queries 
ADD CONSTRAINT fk_query_raised_by 
FOREIGN KEY (raised_by_user_id) REFERENCES users(user_id) ON DELETE SET NULL,
ADD CONSTRAINT fk_query_resolved_by 
FOREIGN KEY (resolved_by_user_id) REFERENCES users(user_id) ON DELETE SET NULL;

ALTER TABLE user_access_log 
ADD CONSTRAINT fk_access_user 
FOREIGN KEY (user_id) REFERENCES users(user_id) ON DELETE SET NULL;

-- ==========================================
-- ADDITIONAL IMPROVEMENTS
-- ==========================================

-- 1. Indexes for performance
CREATE INDEX idx_patients_site ON patients(site_id);
CREATE INDEX idx_patients_status ON patients(patient_status);
CREATE INDEX idx_visits_patient ON patient_visits(patient_id);
CREATE INDEX idx_visits_date ON patient_visits(scheduled_date);
CREATE INDEX idx_ecrf_visit ON ecrf_data(visit_instance_id);
CREATE INDEX idx_labs_patient ON lab_results(patient_id);
CREATE INDEX idx_labs_visit ON lab_results(visit_instance_id);
CREATE INDEX idx_ae_patient ON adverse_events(patient_id);
CREATE INDEX idx_ae_severity ON adverse_events(severity_grade);
CREATE INDEX idx_alerts_severity ON safety_alerts(alert_severity, alert_status);
CREATE INDEX idx_queries_status ON data_queries(query_status);
CREATE INDEX idx_users_role ON users(role, site_id);

-- 2. Materialized views for reporting
CREATE MATERIALIZED VIEW mv_site_enrollment AS
SELECT 
    s.site_id,
    s.institution_name,
    s.target_enrollment,
    s.current_enrollment,
    CASE 
        WHEN s.target_enrollment > 0 
        THEN ROUND((s.current_enrollment::DECIMAL / s.target_enrollment::DECIMAL) * 100, 2)
        ELSE 0 
    END as enrollment_percentage,
    COUNT(DISTINCT p.patient_id) as total_patients,
    COUNT(DISTINCT CASE WHEN p.patient_status = 'Active' THEN p.patient_id END) as active_patients
FROM study_sites s
LEFT JOIN patients p ON s.site_id = p.site_id
GROUP BY s.site_id, s.institution_name, s.target_enrollment, s.current_enrollment;

CREATE MATERIALIZED VIEW mv_safety_overview AS
SELECT 
    t.trial_id,
    t.trial_title,
    COUNT(DISTINCT ae.ae_id) as total_ae,
    COUNT(DISTINCT sae.sae_id) as total_sae,
    COUNT(DISTINCT sa.alert_id) as total_alerts,
    COUNT(DISTINCT pd.deviation_id) as total_deviations
FROM clinical_trials t
LEFT JOIN patients p ON t.trial_id = (SELECT trial_id FROM study_sites WHERE site_id = p.site_id)
LEFT JOIN adverse_events ae ON p.patient_id = ae.patient_id
LEFT JOIN serious_adverse_events sae ON ae.ae_id = sae.ae_id
LEFT JOIN safety_alerts sa ON p.patient_id = sa.patient_id
LEFT JOIN protocol_deviations pd ON p.patient_id = pd.patient_id
GROUP BY t.trial_id, t.trial_title;

-- 3. Function for automatic screening number generation
CREATE OR REPLACE FUNCTION generate_screening_number()
RETURNS TRIGGER AS $$
BEGIN
    IF NEW.screening_number IS NULL THEN
        NEW.screening_number := 'SCR-' || LPAD(NEW.patient_id::TEXT, 6, '0');
    END IF;
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER trg_screening_number
BEFORE INSERT ON patients
FOR EACH ROW
EXECUTE FUNCTION generate_screening_number();

-- 4. Function for automatic enrollment counting
CREATE OR REPLACE FUNCTION update_site_enrollment()
RETURNS TRIGGER AS $$
BEGIN
    IF TG_OP = 'INSERT' THEN
        UPDATE study_sites 
        SET current_enrollment = current_enrollment + 1
        WHERE site_id = NEW.site_id;
    ELSIF TG_OP = 'UPDATE' AND OLD.site_id != NEW.site_id THEN
        -- Patient moved to different site
        UPDATE study_sites 
        SET current_enrollment = current_enrollment - 1
        WHERE site_id = OLD.site_id;
        
        UPDATE study_sites 
        SET current_enrollment = current_enrollment + 1
        WHERE site_id = NEW.site_id;
    ELSIF TG_OP = 'DELETE' THEN
        UPDATE study_sites 
        SET current_enrollment = current_enrollment - 1
        WHERE site_id = OLD.site_id;
    END IF;
    RETURN NULL;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER trg_update_enrollment
AFTER INSERT OR UPDATE OR DELETE ON patients
FOR EACH ROW
EXECUTE FUNCTION update_site_enrollment();

-- 5. Function for critical lab alert generation
CREATE OR REPLACE FUNCTION check_critical_lab()
RETURNS TRIGGER AS $$
DECLARE
    v_test_name VARCHAR;
    v_critical_low NUMERIC;
    v_critical_high NUMERIC;
BEGIN
    -- Get test reference ranges
    SELECT test_name, critical_low_value, critical_high_value 
    INTO v_test_name, v_critical_low, v_critical_high
    FROM laboratory_tests 
    WHERE test_id = NEW.test_id;
    
    -- Check if value is critical
    IF (v_critical_low IS NOT NULL AND NEW.result_value < v_critical_low) OR
       (v_critical_high IS NOT NULL AND NEW.result_value > v_critical_high) THEN
        
        NEW.critical_result_flag := 'Y';
        NEW.result_status := 'Critical';
        
        -- Create safety alert
        INSERT INTO safety_alerts (
            patient_id, source_type, source_table, source_record_id,
            visit_instance_id, alert_code, alert_message, alert_severity,
            measured_value, reference_range_low, reference_range_high,
            threshold_exceeded_percent
        ) VALUES (
            NEW.patient_id, 'LAB_RESULT', 'lab_results', NEW.result_id,
            NEW.visit_instance_id, 'CRITICAL_LAB',
            'Critical ' || v_test_name || ' value: ' || NEW.result_value,
            'CRITICAL',
            NEW.result_value, v_critical_low, v_critical_high,
            CASE 
                WHEN v_critical_low IS NOT NULL AND NEW.result_value < v_critical_low
                THEN ROUND(((v_critical_low - NEW.result_value) / v_critical_low) * 100, 2)
                WHEN v_critical_high IS NOT NULL AND NEW.result_value > v_critical_high
                THEN ROUND(((NEW.result_value - v_critical_high) / v_critical_high) * 100, 2)
                ELSE NULL
            END
        );
    END IF;
    
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER trg_critical_lab
BEFORE INSERT OR UPDATE ON lab_results
FOR EACH ROW
EXECUTE FUNCTION check_critical_lab();

-- 6. Function for SAE escalation
CREATE OR REPLACE FUNCTION escalate_to_sae()
RETURNS TRIGGER AS $$
BEGIN
    -- Check if AE is serious (Grade 4 or 5, or life-threatening/hospitalization/death)
    IF NEW.severity_grade >= 4 OR 
       NEW.life_threatening = TRUE OR 
       NEW.requires_hospitalization = TRUE OR 
       NEW.results_in_death = TRUE THEN
        
        -- Create SAE record
        INSERT INTO serious_adverse_events (
            ae_id, sae_report_number, report_deadline_date
        ) VALUES (
            NEW.ae_id,
            'SAE-' || LPAD(NEW.ae_id::TEXT, 6, '0'),
            CURRENT_DATE + INTERVAL '24 hours' -- 24-hour reporting deadline
        );
        
        -- Create safety alert for SAE
        INSERT INTO safety_alerts (
            patient_id, source_type, source_table, source_record_id,
            visit_instance_id, alert_code, alert_message, alert_severity
        ) VALUES (
            NEW.patient_id, 'ADVERSE_EVENT', 'adverse_events', NEW.ae_id,
            NEW.visit_instance_id, 'SAE',
            'Serious Adverse Event: ' || NEW.ae_term || ' (Grade ' || NEW.severity_grade || ')',
            'SEVERE'
        );
    END IF;
    
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER trg_sae_escalation
AFTER INSERT OR UPDATE ON adverse_events
FOR EACH ROW
EXECUTE FUNCTION escalate_to_sae();

-- 7. Function for 21 CFR Part 11 audit trail
CREATE OR REPLACE FUNCTION audit_table_changes()
RETURNS TRIGGER AS $$
DECLARE
    v_old_data JSONB;
    v_new_data JSONB;
BEGIN
    v_old_data := NULL;
    v_new_data := NULL;
    
    IF TG_OP = 'INSERT' THEN
        v_new_data := row_to_json(NEW)::JSONB;
    ELSIF TG_OP = 'UPDATE' THEN
        v_old_data := row_to_json(OLD)::JSONB;
        v_new_data := row_to_json(NEW)::JSONB;
    ELSIF TG_OP = 'DELETE' THEN
        v_old_data := row_to_json(OLD)::JSONB;
    END IF;
    
    INSERT INTO audit_trail_21cfr (
        table_name, record_id, action_type,
        old_value, new_value, changed_by_user_id,
        change_reason, ip_address, data_hash
    ) VALUES (
        TG_TABLE_NAME,
        COALESCE(NEW.id, OLD.id),
        TG_OP,
        v_old_data,
        v_new_data,
        current_setting('app.current_user_id', TRUE)::INTEGER,
        current_setting('app.change_reason', TRUE),
        inet_client_addr(),
        md5(COALESCE(v_old_data::TEXT, '') || COALESCE(v_new_data::TEXT, '') || TG_OP || TG_TABLE_NAME)
    );
    
    RETURN COALESCE(NEW, OLD);
END;
$$ LANGUAGE plpgsql;

-- Create audit triggers for key tables
CREATE TRIGGER trg_audit_patients
AFTER INSERT OR UPDATE OR DELETE ON patients
FOR EACH ROW EXECUTE FUNCTION audit_table_changes();

CREATE TRIGGER trg_audit_lab_results
AFTER INSERT OR UPDATE OR DELETE ON lab_results
FOR EACH ROW EXECUTE FUNCTION audit_table_changes();

CREATE TRIGGER trg_audit_adverse_events
AFTER INSERT OR UPDATE OR DELETE ON adverse_events
FOR EACH ROW EXECUTE FUNCTION audit_table_changes();

-- 8. View for patient timeline
CREATE VIEW vw_patient_timeline AS
SELECT 
    p.patient_id,
    p.trial_patient_id,
    p.enrollment_date as timeline_date,
    'Enrollment' as event_type,
    'Patient enrolled in study' as description,
    NULL as visit_id,
    NULL as result_value
FROM patients p

UNION ALL

SELECT 
    p.patient_id,
    p.trial_patient_id,
    pv.actual_visit_date as timeline_date,
    'Visit' as event_type,
    CONCAT('Visit: ', vs.visit_name) as description,
    pv.visit_instance_id,
    NULL as result_value
FROM patients p
JOIN patient_visits pv ON p.patient_id = pv.patient_id
JOIN visit_schedules vs ON pv.visit_id = vs.visit_id
WHERE pv.actual_visit_date IS NOT NULL

UNION ALL

SELECT 
    p.patient_id,
    p.trial_patient_id,
    ae.ae_start_date as timeline_date,
    'Adverse Event' as event_type,
    CONCAT('AE: ', ae.ae_term) as description,
    ae.visit_instance_id,
    ae.severity_grade as result_value
FROM patients p
JOIN adverse_events ae ON p.patient_id = ae.patient_id

UNION ALL

SELECT 
    p.patient_id,
    p.trial_patient_id,
    lr.result_date as timeline_date,
    'Critical Lab' as event_type,
    CONCAT('Critical: ', lt.test_name, ' = ', lr.result_value) as description,
    lr.visit_instance_id,
    lr.result_value
FROM patients p
JOIN lab_results lr ON p.patient_id = lr.patient_id
JOIN laboratory_tests lt ON lr.test_id = lt.test_id
WHERE lr.critical_result_flag = 'Y'
ORDER BY patient_id, timeline_date;

-- 9. Function for data export (CDISC SDTM format)
CREATE OR REPLACE FUNCTION export_sdtm_data(p_trial_id INTEGER)
RETURNS TABLE (
    domain VARCHAR(20),
    usubjid VARCHAR(50),
    visitnum INTEGER,
    visit VARCHAR(100),
    param VARCHAR(100),
    paramcd VARCHAR(20),
    aval NUMERIC,
    avalu VARCHAR(20),
    adt DATE,
    atm TIME
) AS $$
BEGIN
    -- DM Domain (Demographics)
    RETURN QUERY
    SELECT 
        'DM'::VARCHAR as domain,
        p.trial_patient_id as usubjid,
        NULL::INTEGER as visitnum,
        NULL::VARCHAR as visit,
        NULL::VARCHAR as param,
        NULL::VARCHAR as paramcd,
        NULL::NUMERIC as aval,
        NULL::VARCHAR as avalu,
        p.enrollment_date as adt,
        NULL::TIME as atm
    FROM patients p
    JOIN study_sites ss ON p.site_id = ss.site_id
    WHERE ss.trial_id = p_trial_id;
END;
$$ LANGUAGE plpgsql;