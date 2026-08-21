package State;

public class NoQuarterState implements State {
    private final GumballMachine machine;
    public NoQuarterState(GumballMachine gumballMachine) {
        machine=gumballMachine;
    }

    @Override
    public void insertQuarter() {
        System.out.println("Quarter accepted");
        machine.setState(machine.getHasQuarterState());
    }

    @Override
    public void ejectQuarter() {
        System.out.println("No quarter to eject");
    }

    @Override
    public void turnCrank() {
        System.out.println("Insert a quarter first");
    }

    @Override
    public void dispense() {
        System.out.println("Payment required");
    }
}
