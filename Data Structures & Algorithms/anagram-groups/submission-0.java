class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
      HashMap<String,List<String>>map = new HashMap<>();
      for(String word : strs){
        char[] chr = word.toCharArray();
        Arrays.sort(chr);
        String str = new String(chr);
        if(!map.containsKey(str)){
          map.put(str,new ArrayList<String>());
        }
        map.get(str).add(word);
      }
      return new ArrayList<>(map.values());
    }
}