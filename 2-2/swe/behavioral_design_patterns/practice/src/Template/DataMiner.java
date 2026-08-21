package Template;

public abstract class DataMiner {
    public final void mine(String path){
        openFile(path);
        String rawData = extractData();
        String data=parseData(rawData);
        analyzeData(data);
        sendReport();
        closeFile();
    }

    protected abstract void openFile(String path);

    protected abstract String extractData();

    protected abstract String parseData(String rawData);

    protected void analyzeData(String data){
        System.out.println("Analyzing data");
    }

    protected void sendReport(){
        System.out.println("Sending report");
    }

    protected abstract void closeFile();

}
