package State;

public class HasQuarterState implements State {
    private final GumballMachine machine;
    public HasQuarterState(GumballMachine gumballMachine) {
        machine=gumballMachine;
    }

    @Override
    public void insertQuarter() {
        System.out.println("Quarter already inserted");
    }

    @Override
    public void ejectQuarter() {
        System.out.println("Quarter returned");
        machine.setState(machine.getNoQuarterState());
    }

    @Override
    public void turnCrank() {
        System.out.println("Crank turned");
        machine.setState(machine.getSoldState());
    }

    @Override
    public void dispense() {
        System.out.println("Turn the crank first");
    }
}
