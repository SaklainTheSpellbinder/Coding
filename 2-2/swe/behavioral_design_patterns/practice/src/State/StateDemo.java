package State;

interface State{
    void insertQuarter();
    void ejectQuarter();
    void turnCrank();
    void dispense();
}

class GumballMachine{

    private final State soldOutState;
    private final State noQuarterState;
    private final State hasQuarterState;
    private final State soldState;

    private State state;
    private int count;

    public GumballMachine(int count){
        this.count=count;

        soldOutState=new SoldOutState(this);
        noQuarterState=new NoQuarterState(this);
        hasQuarterState=new HasQuarterState(this);
        soldState=new SoldState(this);

        state=count>0 ? noQuarterState: soldOutState;
    }

    public void insertQuarter(){
        state.insertQuarter();
    }

    public void ejectQuarter(){
        state.ejectQuarter();
    }

    public void turnCrank(){
        state.turnCrank();
    }

    void setState(State state){
        this.state=state;
    }

    void releaseBall(){
        if(count>0){
            System.out.println("A gumball comes out");
            count--;
        }
    }

    int getCount(){
        return count;
    }

    State getSoldOutState(){
        return soldOutState;
    }

    State getNoQuarterState(){
        return noQuarterState;
    }

    State getHasQuarterState(){
        return hasQuarterState;
    }

    State getSoldState(){
        return soldState;
    }
}

public class StateDemo {
    public static void main(String[] args){
        GumballMachine machine=new GumballMachine(2);
        machine.insertQuarter();
        machine.turnCrank();

        machine.insertQuarter();
        machine.ejectQuarter();
    }
}
