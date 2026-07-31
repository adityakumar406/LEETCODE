class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0;

        for (int i = 0; i < n; i++) {
            char ch = chars[i];
            int count = 0;

            while (i < n && chars[i] == ch) {
                count++;
                i++;
            }

            chars[index++] = ch;

            // Store the count only if greater than 1
            if (count > 1) {
                string str = to_string(count);
                for (char digit : str) {
                    chars[index++] = digit;
                }
            }

            i--; // because the for loop will increment i again
        }

        chars.resize(index);
        return index;
    }
};