package work;

import java.math.*;
import java.io.*;
import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


class Count extends JApplet implements ActionListener  
{  
      
	
    private static final long serialVersionUID = 1L;  
    JTextArea textField = new JTextArea(5,5);  
    String operator = "";
    String input = ""; 
    String ANS = "0";
    boolean flag =  true;  
    public void actionPerformed(ActionEvent e)   
    {  
        int cnt = 0;  
        String actionCommand = e.getActionCommand();  
        if(actionCommand.equals("CE"))
        {
        	input="";
        }
        else if(actionCommand.equals("Space"))
        {
        	if(input.equals("ERROR"));
        	else if(input.length()==0) input="ERROR";
        	else input=input.substring(0,input.length()-1);
        }
        else if(actionCommand.equals("+")||actionCommand.equals("-")||actionCommand.equals("*") ||actionCommand.equals("/"))  
        {
        	if(input.equals("ERROR")) input=actionCommand;
        	int len=input.length()-1;
        	if(len!=-1)
        	{
        		if(input.charAt(len)!=' ') input +=" "+actionCommand+" ";
        		else input +=actionCommand+" ";
        	}
        	else input +=actionCommand+" ";
        }
        else if(actionCommand.equals("ANS"))
        {
        	if(input.equals("ERROR")) input=ANS;
        	else if(input.equals(ANS));
        	else input +=ANS;
        }
        else if(actionCommand.equals("="))
        {  
        	String tmp=compute(input);
            if(tmp=="ERROR") input=tmp;
            else ANS=tmp;
            input=tmp;
        }  
        else
        {
        	if(input==ANS) input=actionCommand;
        	else if(input.equals("ERROR")) input=actionCommand;
        	else
        	{
        		int len=input.length()-1;
            	if(len!=-1)
            	{
            		if((input.charAt(len)<'0'||input.charAt(len)>'9')&&input.charAt(len)!=' ') input +=" "+actionCommand;
            		else input +=actionCommand;
            	}
            	else input +=actionCommand;
        	}
        }
        textField.setText(input);  
    }  
    private String compute(String input)
    {  
        String str[];
        if(input.equals("ERROR")) return input;
        str = input.split(" ");
        if(str[0].equals("+")||str[0].equals("-")||str[0].equals("*")||str[0].equals("/")) return "ERROR";
        for(int i=1;i<str.length;i++) 
        {
        	if((str[i].equals("+")||str[i].equals("-")||str[i].equals("*")||str[i].equals("/"))
        		&&(str[i-1].equals("+")||str[i-1].equals("-")||str[i-1].equals("*")||str[i-1].equals("/"))) return "ERROR";
        }
        int len=str.length-1;
        if(str[len].equals("+")||str[len].equals("-")||str[len].equals("*")||str[len].equals("/")) return "ERROR";
        Stack<BigInteger> s = new Stack<BigInteger>();  
        BigInteger m = new BigInteger(str[0]);  
        s.push(m);  
        for(int i=1;i<str.length;i++)  
        {  
            if(i%2==1)    
            {    
                if(str[i].compareTo("+")==0)    
                {    
                    BigInteger help = new BigInteger(str[i+1]);    
                    s.push(help);    
                }    
                    
                if(str[i].compareTo("-")==0)
                {    
                    BigInteger help = new BigInteger(str[i+1]); 
                    help.multiply(new BigInteger("-1"));
                    s.push(help);    
                }    
                    
                if(str[i].compareTo("*")==0)    
                {    
                    BigInteger help = new BigInteger(str[i+1]);    
                    BigInteger ans = s.peek();
                    s.pop();
                    ans=ans.multiply(help);
                    s.push(ans);    
                }    
                    
                if(str[i].compareTo("/")==0)    
                {    
                    BigInteger help = new BigInteger(str[i+1]);    
                    BigInteger ans = s.peek();    
                    s.pop();
                    if(help.equals(new BigInteger("0"))) return "ERROR";
                    ans=ans.divide(help);  
                    s.push(ans);    
                }    
            }    
        }    
        BigInteger ans = new BigInteger("0"); 
        while(!s.isEmpty())    
        {    
            ans=ans.add(s.peek());
            s.pop();    
            
        }    
        String result = ans.toString();  
        return result;
    }  
}
public class Main 
{
	
	public static void main(String[] args)
	{
		JFrame f = new JFrame("¼ÆËãÆ÷");
        Count applet = new Count();  
        f.getContentPane().add(applet, BorderLayout.CENTER);  
        
		applet.init();
		applet.textField.setFont(new Font("", Font.PLAIN, 20));
		Container C = applet.getContentPane();  
        JButton b[] = new JButton[18];  
        JPanel panel = new JPanel();  
        C.add(applet.textField, BorderLayout.NORTH);  
        C.add(panel,BorderLayout.CENTER);  
        panel.setLayout(new GridLayout(5,4));  
        String name[]={"7","8","9","+","4","5","6","-","1","2","3","*","0","ANS","=","/","Space","CE"}; 
        for(int i=0;i<18;i++)
        {  
            b[i] = new JButton(name[i]);
            b[i].setFont(new Font("", Font.PLAIN, 25));  
            panel.add(b[i]);  
            b[i].addActionListener(applet);  
        }  
		applet.start();

		f.setBounds(500,500,500,500);
		f.setVisible(true);
	}
}
