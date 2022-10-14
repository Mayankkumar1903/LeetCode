class Solution {
    public String[] sortPeople(String[] names, int[] heights) {
        
        String str[]=new String[names.length];
		HashMap<Integer,String>hm=new HashMap<>();
		for(int i=0;i<names.length;i++)
			hm.put(heights[i],names[i]);

		List<Integer>list=new ArrayList<>(hm.keySet());

		Collections.sort(list, Collections.reverseOrder()); 
		int a=0;
		for(int i:list){
		   str[a]=hm.get(i);
		   a++;
		}
		return str;
    }
}