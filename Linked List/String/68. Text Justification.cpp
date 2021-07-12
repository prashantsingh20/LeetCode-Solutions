//68. Text Justification
//https://leetcode.com/problems/text-justification/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> V, ans;
        int cnt = 0, slot;
        V.push_back(words[0]);
        cnt = words[0].size();
        for(int i = 1; i < words.size(); i++){
			//find how many words can be assigned in a line.(we have to considered the num of spaces. Spaces between words is at least one)
            if(cnt + words[i].size() + 1 <= maxWidth){
                cnt += words[i].size() + 1;
                V.push_back(" " + words[i]);
            }
            else{
                string tmp = V[0];
				// how many extra spaces need to be assigned in a line.
                slot = maxWidth - cnt;
                int MAXN = V.size();
				//if only one word, this line is also left-justified
                if(MAXN == 1)
                    tmp += string(slot, ' ');
                else{
                    int d = slot / (MAXN - 1), r = slot % (MAXN - 1);
					//If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
                    for(int i = 1; i < MAXN; i++){
                        if(i <= r)
                            tmp += string(d+1, ' ') + V[i];
                        else
                            tmp += string(d, ' ') + V[i];
                    }
                }
                ans.push_back(tmp);
                V.clear();
                V.push_back(words[i]);
                cnt = words[i].size();
            }
        }
		//For the last line of text, it should be left justified and no extra space is inserted between words.
        if(V.size()){
            slot = maxWidth - cnt;
            int MAXN = V.size();
            string tmp = V[0];
            for(int i = 1; i < V.size(); i++)
                tmp += V[i];
            tmp += string(slot, ' ');
            ans.push_back(tmp);
        }
        return ans;
    }
};