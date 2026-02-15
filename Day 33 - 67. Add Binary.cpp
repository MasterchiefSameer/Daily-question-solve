// Bit Manupulation 
class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int bitA = (i >= 0) ? a[i--] - '0' : 0;
            int bitB = (j >= 0) ? b[j--] - '0' : 0;

            // --- Bitwise Logic Start ---
            
            // 1. Current Sum bit: (bitA XOR bitB XOR carry)
            int sum = bitA ^ bitB ^ carry;
            res += (sum + '0');

            // 2. New Carry bit: (bitA AND bitB) OR (carry AND (bitA XOR bitB))
            // Matlab: Carry tab aayega jab koi bhi do bits '1' hon
            carry = (bitA & bitB) | (carry & (bitA ^ bitB));
            
            // --- Bitwise Logic End ---
        }

        reverse(res.begin(), res.end());
        return res;
    }
};



// 2nd Method: formal way with carry and sum calculation
class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int carry = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        for (int i = 0; i < max(a.length(), b.length()); i++) {
            int digitA = i < a.length() ? a[i] - '0' : 0;
            int digitB = i < b.length() ? b[i] - '0' : 0;

            int total = digitA + digitB + carry;
            char c = (total % 2) + '0';
            result += c;
            carry = total / 2;
        }
        if (carry)
            result += '1';

        reverse(result.begin(), result.end());
        return result;
    }
};