class Solution {
    public String simplifyPath(String path) {
// first seperate all the tokens using / as tokenizer
//         then check if its empty continue , . then also continue, and if ".."then pop the top element from stack
//         return 
      
      String[] paths = path.split("/");
        Stack<String> st = new Stack<>();
        for(String s:paths){
            if(s.equals("")) continue;
            else if(s.equals(".")) continue;
            else if(s.equals("..")) 
                if(!st.isEmpty()) st.pop();
                else continue;
            else st.add(s);
        }
        return "/"+String.join("/", st);
    }
}