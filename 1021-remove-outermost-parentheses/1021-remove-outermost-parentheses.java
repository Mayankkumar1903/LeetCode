class Solution {
    public String removeOuterParentheses(String s) {
          StringBuilder sb = new StringBuilder();
        Stack<Character> st = new Stack<>();
        for(char c : s.toCharArray()){
            if(st.isEmpty() && c == '('){
                st.push(c);
            }
            else if(!st.isEmpty() && c == '('){
                st.push(c);
                sb.append(c);
            }
            else if(st.size() >1 && c == ')'){
                st.pop();
                sb.append(c);
            }
            else if(st.size() == 1 && c == ')'){
                st.pop();
            }
        }
        return sb.toString();
    }
}