package Composite;

import java.util.ArrayList;
import java.util.List;

interface FileSystemComponent{
    void showDetails();
}

class File implements FileSystemComponent{
    String name;
    public File(String name){
        this.name=name;
    }

    @Override
    public void showDetails() {
        System.out.println("  File: "+name);
    }
}

class Directory implements FileSystemComponent{
    String name;
    private List<FileSystemComponent> files=new ArrayList<>();
    public Directory(String name){
        this.name=name;
    }

    void add(FileSystemComponent f){
        files.add(f);
    }

    void remove(FileSystemComponent f){
        files.remove(f);
    }

    @Override
    public void showDetails() {
        System.out.println("Dir: "+name);
        for(FileSystemComponent f:files){
            f.showDetails();
        }
    }
}

public class FileSystemClient {
    public static void main(String[] args){
        FileSystemComponent file1=new File("resume.pdf");
        FileSystemComponent file2=new File("photo.jpg");
        FileSystemComponent file3=new File("budget.xlsx");

        Directory personalfolder=new Directory("Personal");
        Directory financefolder=new Directory("Finance");
        Directory rootfolder=new Directory("Root");

        personalfolder.add(file1);
        personalfolder.add(file2);

        financefolder.add(file3);

        rootfolder.add(personalfolder);
        rootfolder.add(financefolder);

        rootfolder.showDetails();
    }
}
