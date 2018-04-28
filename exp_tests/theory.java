import java.util.Stack;

class theory {
    public static boolean evaluateBool(String s)
{
    Stack<Object> stack = new Stack<>();
    StringBuilder expression =new StringBuilder(s);
    expression.chars().forEach(ch->
    {
        if(ch=='0') stack.push(false);  
         else if(ch=='1') stack.push(true); 
          else if(ch=='A'||ch=='R'||ch=='X')
          {
              boolean op1 = (boolean) stack.pop();
              boolean op2 = (boolean) stack.pop();
              switch(ch)
              {
                case 'A' : stack.push(op2&&op1); break;
                case 'R' : stack.push(op2||op1); break;
                case 'X' : stack.push(op2^op1); break;
              }//endSwitch  
          }else 
              if(ch=='N')
                {
                  boolean op1 = (boolean) stack.pop();
                  stack.push(!op1);
                }//endIF
    });
    return (boolean) stack.pop();
}
}