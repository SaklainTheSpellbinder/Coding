package State;
public class WinnerState implements State {
    private final GumballMachine machine;

    public WinnerState(
            GumballMachine machine) {

        this.machine = machine;
    }

    @Override
    public void dispense() {
        System.out.println(
                "Winner! Two gumballs"
        );

        machine.releaseBall();

        if (machine.getCount() == 0) {
            machine.setState(
                    machine.getSoldOutState()
            );

            return;
        }

        machine.releaseBall();

        if (machine.getCount() > 0) {
            machine.setState(
                    machine.getNoQuarterState()
            );
        } else {
            machine.setState(
                    machine.getSoldOutState()
            );
        }
    }

    @Override
    public void insertQuarter() {
        System.out.println("Please wait");
    }

    @Override
    public void ejectQuarter() {
        System.out.println(
                "Cannot eject now"
        );
    }

    @Override
    public void turnCrank() {
        System.out.println(
                "Already turned"
        );
    }
}
