class Solution {
    public int maxDepth(String s) {
        int maxdepth=0;
        int count=0;
        Stack <Character> stack=new Stack<>();
        for(int i=0;i<s.length();i++){
           char ch=s.charAt(i);
            if(ch=='('){
                stack.push(ch);
                count++;
            }
           
            else if(ch==')'){
                stack.pop();
                count--;
            }
             maxdepth=count>maxdepth?count:maxdepth;
        }
        // maxdepth=count>maxdepth?count:maxdepth;
        return maxdepth;
    }
}