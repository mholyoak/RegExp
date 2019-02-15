#include <iostream>
#include <vector>

using std::string;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (!containsSpecialChar(p))
        {
            return s == p;
        }
        else
        {
            auto subSection = getSubSection(p);

        }

        return false;
    }

private:
    const char _anyChar = '.';
    const char _anyCount = '*';
    const char _escapeChar = '\\';

    struct SubSection {
        enum class SectionType {
            stringSection,
            expressionSection
        };

        SubSection(SectionType sectionType, string value) :
            _sectionType(sectionType),
            _value(value)
        {

        }

        SectionType _sectionType;
        string      _value;
    };

    bool containsSpecialChar(const string& s) const
    {
        bool hasAnyChar = string::npos != s.find(_anyChar);
        bool hasAnyCount = string::npos != s.find(_anyCount);

        return hasAnyChar || hasAnyCount;
    }

    size_t findSpecialChar(const string& s) const
    {
        size_t findPos = string::npos;
    }

    std::vector<string> getSubSections(const string& s) const
    {
        std::vector<string> subSections;
        std::vector<char> specialChars;
        specialChars.push_back(_anyChar);
        specialChars.push_back(_anyCount);

        string curSection;
        bool previousCharEscape = false;
        for (int i = 0; i < s.length(); i++)
        {
            char curChar = s[i];
            if (previousCharEscape)
            {
                curSection += curChar;
            }
            else
            {
                bool specialChar = std::any_of(specialChars.begin(), specialChars.end(), [curChar](char specChar)
                                    {
                                        return curChar == specChar;
                                    });


            }

            previousCharEscape = _escapeChar == curChar;
        }


    }

};

struct RegTest
{
    //RegTest() {};
    RegTest(string s, string p, string exp) :
        searchStr(s),
        regEx(p),
        expectedResult(exp)
    {

    }

    string searchStr;
    string regEx;
    string expectedResult;
};

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::vector<RegTest> testVector;

    testVector.push_back(RegTest("aa", "a", "False"));
    testVector.push_back(RegTest("abc", "abc", "True"));
    testVector.push_back(RegTest("aa", "a*", "True"));
    testVector.push_back(RegTest("ab", ".*", "True"));
    testVector.push_back(RegTest("aab", "c*a*b", "True"));
    testVector.push_back(RegTest("mississippi", "mis*is*p*.", "False"));
    testVector.push_back(RegTest("a.", "a\.", "True"));
    testVector.push_back(RegTest("ab", "a\.", "False"));
    testVector.push_back(RegTest("a*", "a\*", "True"));

    Solution testSol;

    for(auto test : testVector)
    {
        std::cout << "Expected: " << test.expectedResult << " " <<
            std::to_string(testSol.isMatch(test.searchStr, test.regEx)) <<
            " Match s: " << test.searchStr <<
            " p: " << test.regEx <<  std::endl;
    }

    return 0;
}