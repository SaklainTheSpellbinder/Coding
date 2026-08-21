package Mediator;

import java.awt.*;

interface Mediator{
    void notify(Component sender, String event);
}

abstract class Component{
    protected final Mediator mediator;

    protected Component(Mediator mediator){
        this.mediator=mediator;
    }
}

class CheckBox extends Component{
    private boolean checked;

    public CheckBox(Mediator mediator){
        super(mediator);
    }

    public void setChecked(boolean checked){
        this.checked=checked;
        mediator.notify(this,"checked-changed");
    }

    public boolean isChecked(){
        return checked;
    }
}

class TextField extends Component{
    private String text="";
    private boolean enabled=true;

    public TextField(Mediator mediator){
        super(mediator);
    }

    public void setText(String text){
        this.text=text;
        mediator.notify(this,"text-changed");
    }

    public String getText(){
        return text;
    }

    public void setEnabled(boolean enabled){
        this.enabled=enabled;
        System.out.println("Text field enabled: "+enabled);
    }

    public boolean isEnabled(){
        return enabled;
    }
}

class Button extends Component{
    public Button(Mediator mediator){
        super(mediator);
    }

    public void click(){
        mediator.notify(this,"click");
    }
}

class ProfileDIalog implements Mediator{
    private final CheckBox businessCheckBox;
    private final TextField companyNameField;
    private final Button applyButton;

    public ProfileDIalog(){
        businessCheckBox=new CheckBox(this);
        companyNameField=new TextField(this);
        applyButton=new Button(this);

        companyNameField.setEnabled(false);
    }

    @Override
    public void notify(Component sender, String event) {
        if(sender==businessCheckBox && event.equals("checked-changed")){
            companyNameField.setEnabled(businessCheckBox.isChecked());
        }
        else if(sender==applyButton && event.equals("click")){
            validateAndSave();
        }
    }

    private void validateAndSave(){
        if(businessCheckBox.isChecked() && companyNameField.getText().isBlank()){
            System.out.println("Company name is required");
        }
        else{
            System.out.println("Profile saved");
        }
    }

    public CheckBox getBusinessCheckBox(){
        return businessCheckBox;
    }

    public TextField getCompanyNameField() {
        return companyNameField;
    }

    public Button getApplyButton() {
        return applyButton;
    }
}

public class MediatorDemo {
    public static void main(String[] args){
        ProfileDIalog dialog=new ProfileDIalog();

        dialog.getBusinessCheckBox().setChecked(true);
        dialog.getCompanyNameField().setText("ABC Ltd.");
        dialog.getApplyButton().click();
    }
}
