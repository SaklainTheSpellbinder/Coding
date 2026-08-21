package Template;

abstract class CaffeineBeverage{
    public final void prepareRecipe(){
        boilWater();
        brew();
        pourInCup();

        if(customerWantsCondiments()){
            addCondiments();
        }
    }

    // primitive operations : subclasses must implement
    protected abstract void brew();

    protected abstract void addCondiments();

    //common concrete steps
    private void boilWater(){
        System.out.println("Boiling water");
    }

    private void pourInCup(){
        System.out.println("Pouring into cup");
    }

    //optional extension point
    protected boolean customerWantsCondiments(){
        return true;
    }
}

class Coffee extends CaffeineBeverage{
    @Override
    protected void brew() {
        System.out.println("Brewing coffee through filter");
    }

    @Override
    protected void addCondiments() {
        System.out.println("Adding sugar and milk");
    }
}

class Tea extends CaffeineBeverage{
    @Override
    protected void brew() {
        System.out.println("Steeping tea");
    }

    @Override
    protected void addCondiments() {
        System.out.println("Adding lemon");
    }
}

class BlackCoffee extends Coffee{
    @Override
    protected boolean customerWantsCondiments() {
        return false;
    }
}

public class TemplateMethodDemo {
    public static void main(String[] args){
        CaffeineBeverage tea =new Tea();
        tea.prepareRecipe();

        CaffeineBeverage coffee=new Coffee();

        coffee.prepareRecipe();
    }
}
