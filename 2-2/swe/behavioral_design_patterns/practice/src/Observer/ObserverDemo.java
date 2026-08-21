package Observer;

import java.util.ArrayList;
import  java.util.List;

interface Subject{
    void registerObserver(Observer observer);

    void removeObserver(Observer observer);

    void notifyObservers();
}

interface Observer{
    void update(float temperature, float humidity, float pressure);
}

class WeatherData implements Subject{
    private final List<Observer> observers=new ArrayList<>();

    private float temperature;
    private float humidity;
    private float pressure;


    @Override
    public void registerObserver(Observer observer) {
        if(!observers.contains(observer)){
            observers.add(observer);
        }
    }

    @Override
    public void removeObserver(Observer observer) {
        observers.remove(observer);
    }

    @Override
    public void notifyObservers() {
        //copy protects the iteration if an observer unsubscribes while being notified
        List<Observer> snapshot=new ArrayList<>(observers);

        for(Observer observer : snapshot){
            observer.update(temperature,humidity,pressure);
        }
    }

    public void setMeasurements(float temperature,float humidity,float pressure){
        this.temperature=temperature;
        this.humidity=humidity;
        this.pressure=pressure;

        measurementsChanged();
    }

    public void measurementsChanged(){
        notifyObservers();
    }

}


class CurrentConditionsDisplay implements Observer{
    private float temperature;
    private float humidity;

//    public CurrentConditionsDisplay(Subject subject) {
//        subject.registerObserver(this);
//    }

    @Override
    public void update(float temperature, float humidity, float pressure) {
        this.temperature=temperature;
        this.humidity=humidity;
        display();
    }

    public void display(){
        System.out.println("Current: "+temperature+"C, "+humidity+"% humidity");
    }
}

class ForecastDisplay implements Observer{

    @Override
    public void update(float temperature, float humidity, float pressure) {
        if(pressure>1013){
            System.out.println("Forecast: improving weather");
        }
        else{
            System.out.println("Forecast: possible rain");
        }
    }
}

public class ObserverDemo {
    public static void main(String[] args){
        WeatherData weatherData=new WeatherData();

        Observer current=new CurrentConditionsDisplay();
        Observer forecast=new ForecastDisplay();

        weatherData.registerObserver(current);
        weatherData.registerObserver(forecast);

        weatherData.setMeasurements(30.0f,75.0f,1008.0f);
        weatherData.removeObserver(forecast);
        weatherData.setMeasurements(28.0f,80.0f,1015.0f);
    }
}

//interface Subscription {
//    void unsubscribe();
//}

//Subscription subscription =
//        weatherData.subscribe(display);
//
//subscription.unsubscribe();
