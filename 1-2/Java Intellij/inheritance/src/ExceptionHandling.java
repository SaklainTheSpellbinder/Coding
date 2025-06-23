public class ExceptionHandling {
    public static void main(String[] args){
        //exception handling mainly tthrowable class ke inherit kore banay...
        //throwable class eer under e ache exception class....etar moddheei mainly amra amader class tao banai.....and runtime error and others...orao etar bhitor ee thake
        //finally dile oita kora ee laage

        try {
            int arr[]=new int[10];
            //System.out.println(arr[10]);
            throw new Exception("Yayyayayayayaya cholo more jai");///emon new kono exception banay dile oita hoy por por ctach korte hoy....or ei method er declaration er shomoy throws Exception eta likhte hoy
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("out of bounds\n");
        }
        catch(Exception e){
            System.out.println("pore gele betha paba" + e.getMessage());///ei ta catch na korle  mara
        }
        finally{
            System.out.println("yayy");
        }

    }    
}
