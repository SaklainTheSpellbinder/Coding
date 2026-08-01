package Adapter;

class AdvancedAnalyticsLibrary{
    public void generateCharts(String jsonData){
        System.out.println("Hehe json now from "+jsonData);
    }
}

interface AnalyticsTool{
    void processStockData(String xmlData);
}

class XmlToJsonAdapter implements AnalyticsTool{
    private AdvancedAnalyticsLibrary thirdPartyLibrary;

    public XmlToJsonAdapter(AdvancedAnalyticsLibrary tintin){
        thirdPartyLibrary=tintin;
    }
    @Override
    public void processStockData(String xmlData) {
        thirdPartyLibrary.generateCharts(xmlData);
    }
}

public class StockMarketApp {

}
