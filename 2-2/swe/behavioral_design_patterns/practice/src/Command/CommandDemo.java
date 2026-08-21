package Command;

import javax.sql.CommonDataSource;
import java.util.ArrayDeque;
import java.util.Deque;

interface Command{
    void execute();

    default void undo(){
        //Commands without undo need do nothing
    }

    default boolean isUndoable(){
        return false;
    }
}

// receiver
class Editor{
    private String text="";

    public String getText(){
        return text;
    }

    public void setText(String text){
        this.text=text;
        System.out.println("Editor text: "+text);
    }

    public void append(String value){
        setText(text+value);
    }

    public void save(){
        System.out.println("Saving: "+text);
    }
}

//concrete commands

class SaveCommand implements Command{
    private final Editor editor;

    public SaveCommand(Editor editor){
        this.editor=editor;
    }

    @Override
    public void execute() {
        editor.save();
    }
}

class AppendTextCommand implements Command{
    private final Editor editor;
    private final String value;

    private String backup;

    public AppendTextCommand(Editor editor,String value){
        this.editor=editor;
        this.value=value;
    }

    @Override
    public void execute() {
        backup=editor.getText();
        editor.append(value);
    }

    @Override
    public void undo() {
        editor.setText(backup);
    }

    @Override
    public boolean isUndoable() {
        return true;
    }
}

//invokers
class Button{
    private final Command command;

    public Button(Command command){
        this.command=command;
    }

    public void click(){
        command.execute();
    }
}

class MenuItem{
    private final Command command;

    public MenuItem(Command command){
        this.command=command;
    }

    public void select(){
        command.execute();
    }
}

class Shortcut{
    private final Command command;

    public Shortcut(Command command){
        this.command=command;
    }

    public void press(){
        command.execute();;
    }
}

class CommandManager{
    private final Deque<Command> history=new ArrayDeque<>();

    public void execute(Command command){
        command.execute();

        if(command.isUndoable()) {
            history.push(command);
        }
    }

    public void undo(){
        if(!history.isEmpty()){
            history.pop().undo();
        }
    }
}

public class CommandDemo{
    public static void main(String[] args){
        Editor editor=new Editor();
        Command save=new SaveCommand(editor);
        Button saveButton=new Button(save);
        MenuItem saveMenu=new MenuItem(save);
        Shortcut ctrIS=new Shortcut(save);

        saveButton.click();
        saveMenu.select();
        ctrIS.press();

        CommandManager manager=new CommandManager();

        manager.execute(new AppendTextCommand(editor,"Hello"));
        manager.execute(new AppendTextCommand(editor,"World"));

        manager.undo();
    }
}