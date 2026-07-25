class GameConfig{
    private int resolution;
    private int audioVolume;
    private int difficultyLevel;


    private static GameConfig instance;

    public int getResolution() {
        return resolution;
    }
    public void setResolution(int resolution) {
        this.resolution = resolution;
    }
    public int getAudioVolume() {
        return audioVolume;
    }
    public void setAudioVolume(int audioVolume) {
        this.audioVolume = audioVolume;
    }
    public int getDifficultyLevel() {
        return difficultyLevel;
    }
    public void setDifficultyLevel(int difficultyLevel) {
        this.difficultyLevel = difficultyLevel;
    }

    private GameConfig(){
        resolution=1080;
        audioVolume=80;
        difficultyLevel=3;
    }

    public static synchronized GameConfig getInstance(){
        if(instance==null){
            instance=new GameConfig();
        }
        return instance;
    }
}

public class Main3 {
    public static void main(String[] args) {
        GameConfig in1= GameConfig.getInstance();
        GameConfig in2=GameConfig.getInstance();

        in1.setAudioVolume(30);
        System.out.println(in2.getAudioVolume());

        System.out.println(in1==in2);

    }
}
