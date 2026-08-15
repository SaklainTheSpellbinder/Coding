import matplotlib.pyplot as plt
import numpy as np

# -------------------------------------------------------------
# 1. Setup Time Domain and Frequency Domain Grids
# -------------------------------------------------------------
T = 20.0  # Time window [-T/2, T/2] large enough to capture periods
t = np.linspace(-T / 2, T / 2, 2000)
dt = t[1] - t[0]

# Frequency grid (in Hz: f = omega / (2*pi))
f = np.linspace(-3, 3, 1000)  # spans around +/- 4/(2*pi) and 6/(2*pi)


# -------------------------------------------------------------
# 2. Numerical CFT via np.trapezoid / np.trapz (No np.fft)
# -------------------------------------------------------------
def cft_numerical(signal_t, t_grid, f_grid):
    """Computes X(f) = integral( x(t) * exp(-j * 2*pi * f * t) dt ) using trapezoidal integration"""
    # 2D broadcasting: (len(f), len(t))
    kernel = np.exp(-1j * 2 * np.pi * f_grid[:, None] * t_grid[None, :])
    integrand = signal_t[None, :] * kernel

    # Numerical integration across the time axis (axis=1)
    # Note: Use np.trapezoid (NumPy 2.0+) or np.trapz (older NumPy)
    if hasattr(np, 'trapezoid'):
        return np.trapezoid(integrand, t_grid, axis=1)
    return np.trapz(integrand, t_grid, axis=1)


# -------------------------------------------------------------
# 3. Define Signals: x(t) and its analytical derivatives
# -------------------------------------------------------------
# x(t) = 0.5*cos(4t) + 0.5*sin(6t)
x = 0.5 * np.cos(4 * t) + 0.5 * np.sin(6 * t)

# y1(t) = d/dt x(t) = -2*sin(4t) + 3*cos(6t)
y1 = -2.0 * np.sin(4 * t) + 3.0 * np.cos(6 * t)

# y2(t) = d^2/dt^2 x(t) = -8*cos(4t) - 18*sin(6t)
y2 = -8.0 * np.cos(4 * t) - 18.0 * np.sin(6 * t)

# y3(t) = d^3/dt^3 x(t) = 32*sin(4t) - 108*cos(6t)
y3 = 32.0 * np.sin(4 * t) - 108.0 * np.cos(6 * t)

# -------------------------------------------------------------
# 4. Compute Direct CFTs and Derivative Property CFTs
# -------------------------------------------------------------
X_f = cft_numerical(x, t, f)
Y1_direct = cft_numerical(y1, t, f)
Y2_direct = cft_numerical(y2, t, f)
Y3_direct = cft_numerical(y3, t, f)

# CFT Derivative Property: F{ d^n/dt^n x(t) } = (j * 2*pi * f)^n * X(f)
j2pif = 1j * 2 * np.pi * f
Y1_prop = j2pif * X_f
Y2_prop = (j2pif**2) * X_f
Y3_prop = (j2pif**3) * X_f


# -------------------------------------------------------------
# 5. Helper Function to Clean Phase & Compute MSE
# -------------------------------------------------------------
def get_magnitude_and_phase(cft_val, thresh=1e-2):
    mag = np.abs(cft_val)
    phase = np.angle(cft_val)
    # Mask out phase where magnitude is negligible noise
    phase[mag < thresh * np.max(mag)] = 0.0
    return mag, phase


def compute_mse(actual, expected):
    return np.mean((actual - expected) ** 2)


# -------------------------------------------------------------
# 6. Plotting Magnitude and Phase Comparisons
# -------------------------------------------------------------
pairs = [
    (1, Y1_direct, Y1_prop, '1st Derivative (y1)'),
    (2, Y2_direct, Y2_prop, '2nd Derivative (y2)'),
    (3, Y3_direct, Y3_prop, '3rd Derivative (y3)'),
]

fig, axes = plt.subplots(3, 2, figsize=(14, 10))

for idx, Y_dir, Y_pr, title in pairs:
    row = idx - 1

    mag_dir, ph_dir = get_magnitude_and_phase(Y_dir)
    mag_pr, ph_pr = get_magnitude_and_phase(Y_pr)

    # Calculate MSE
    mse_mag = compute_mse(mag_dir, mag_pr)
    mse_phase = compute_mse(ph_dir, ph_pr)
    print(
        f'{title} -> MSE Magnitude: {mse_mag:.4e} | MSE Phase: {mse_phase:.4e}'
    )

    # --- Plot Magnitude ---
    axes[row, 0].plot(
        f,
        mag_dir,
        'b-',
        label=r'$|\mathcal{F}\{\frac{d^n}{dt^n}x(t)\}|$',
        linewidth=2,
    )
    axes[row, 0].plot(
        f,
        mag_pr,
        'r--',
        label=r'$|(j2\pi f)^n X(f)|$',
        linewidth=1.5,
    )
    axes[row, 0].set_title(f'{title}: Magnitude Comparison (MSE: {mse_mag:.2e})')
    axes[row, 0].set_xlabel('Frequency (Hz)')
    axes[row, 0].set_ylabel('Magnitude')
    axes[row, 0].grid(True, alpha=0.3)
    axes[row, 0].legend()

    # --- Plot Phase ---
    axes[row, 1].plot(
        f,
        ph_dir,
        'b-',
        label=r'$\angle \mathcal{F}\{\frac{d^n}{dt^n}x(t)\}$',
        linewidth=2,
    )
    axes[row, 1].plot(
        f, ph_pr, 'r--', label=r'$\angle ((j2\pi f)^n X(f))$', linewidth=1.5
    )
    axes[row, 1].set_title(f'{title}: Phase Comparison (MSE: {mse_phase:.2e})')
    axes[row, 1].set_xlabel('Frequency (Hz)')
    axes[row, 1].set_ylabel('Phase (radians)')
    axes[row, 1].grid(True, alpha=0.3)
    axes[row, 1].legend()

plt.tight_layout()
plt.show()