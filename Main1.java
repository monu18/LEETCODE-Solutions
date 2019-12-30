import java.util.*;
import java.lang.*;
class Solution {
    public String defangIPaddr(String address) {
       // String ss=new String();
        int len = address.length();
       	//address=address.substring(0,i)+'['+address.substring(i);
       	//address=address.replace('.', '[.]');
        for (int i = 0; i < address.length(); i++) {
			if (address.charAt(i)=='.') {
				address=address.substring(0,i)+"[.]"+address.substring(i+1);
				i++;
			}
		}
        return address;

    }
}


public class Main1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		String address=sc.nextLine();
		Solution karn=new Solution();
		System.out.println(karn.defangIPaddr(address));
	}

}
