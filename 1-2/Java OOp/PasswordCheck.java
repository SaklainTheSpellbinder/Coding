/*
 * 🔎 What does "\\d" mean?
. → any character (except newline)

* → zero or more times

\\d → a digit (0–9)

.*\\d.* → means:
“Contains at least one digit anywhere in the string”

⚠️ In Java, double backslash \\ is used because \d is a special regex symbol, but Java needs the \ to be escaped.


*/



class User {
    private String password;

    public void setPassword(String password) {
        // Minimum 8 characters, must contain a digit
        if (password.length() >= 8 && password.matches(".*\\d.*"))
            this.password = password;
        else
            System.out.println("Password too weak!");
    }

    public String getPassword() {
        System.err.println(password);
        return "Access Denied: Use authentication methods!";
    }
}


public class PasswordCheck {
    public static void main(String[] args){
        User u=new User();
        u.setPassword("Hello000yayayyayayayayay");
        System.err.println(u.getPassword());
    }
}
