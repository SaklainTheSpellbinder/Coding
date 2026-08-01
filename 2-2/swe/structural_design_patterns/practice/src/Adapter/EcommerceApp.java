package Adapter;

interface PaymentProcess{
    void payInUSD(double amountInDollars);
}

class EuroPaymentGateway{
    public void processEuroPayment(double amountInEuro){
        System.out.println("Processing European payment of "+amountInEuro);
    }
}

class EuroPaymentAdapter implements PaymentProcess{
    EuroPaymentGateway eurogate;
    public EuroPaymentAdapter(EuroPaymentGateway eurogate){
        this.eurogate=eurogate;
    }

    @Override
    public void payInUSD(double amountInDollars) {
        eurogate.processEuroPayment(0.91*amountInDollars);
    }
}

public class EcommerceApp {
    public static void main(String[] args){
        EuroPaymentGateway externalGateway=new EuroPaymentGateway();
        PaymentProcess paymentSystem=new EuroPaymentAdapter(externalGateway);

        paymentSystem.payInUSD(100.00);
    }
}
