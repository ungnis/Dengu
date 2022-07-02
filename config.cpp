#include <set>
#include <vector>
#include <string>

const std::set<std::string> vowels =
{
    "a", "á", 
    "e", "é", 
    "i", "í", 
    "o", "ó", 
    "u", "ú"
};

const std::set<std::string> endings = 
{
    "as", "ás", 
    "is", "ís", 
    "os", "ós", 
    "us", "ús", 
    "om", "óm", 
    "onts", "ónts", 
    "ti" 
};

const std::set<std::string> diphtongs = 
{
    "ey", "éy",
    "oy", "óy",
    "ew", "éw",
    "ow", "ów", 
    "wu", "wú", 
    "l̥h₁", "ĺ̥h₁",
    "r̥h₁", "ŕ̥h₁",
    "m̥h₁", "ḿ̥h₁",
    "n̥h₁", "ń̥h₁"
};

std::vector<std::pair<std::string,std::string>> change =
{
    std::make_pair("ʰ", ""),
    std::make_pair("ǵ", "g"),
    std::make_pair("ḱ", "k"),
    std::make_pair("l̥h₁", "le"),
    std::make_pair("ĺ̥h₁", "lé"),
    std::make_pair("r̥h₁", "re"),
    std::make_pair("ŕ̥h₁", "ré"),
    std::make_pair("m̥h₁", "me"),
    std::make_pair("ḿ̥h₁", "mé"),
    std::make_pair("n̥h₁", "ne"),
    std::make_pair("ń̥h₁", "ne"),
    std::make_pair("wl̥", "wol"),
    std::make_pair("wĺ̥", "wól"),
    std::make_pair("l̥", "el"),
    std::make_pair("ĺ̥", "él"),
    std::make_pair("r̥", "er"),
    std::make_pair("ŕ̥", "ér"),
    std::make_pair("m̥", "em"),
    std::make_pair("ḿ̥", "ém"),
    std::make_pair("n̥", "en"),
    std::make_pair("ń̥", "én"),
    std::make_pair("ʷ", "w"),
    std::make_pair("ti", ""),
    std::make_pair("as", "a"),
    std::make_pair("ás", "á"),
    std::make_pair("is", "i"),
    std::make_pair("ís", "í"),
    std::make_pair("os", "o"),
    std::make_pair("ós", "ó"),
    std::make_pair("us", "u"),
    std::make_pair("ús", "ú"),
    std::make_pair("om", "o"),
    std::make_pair("óm", "ó"),
    std::make_pair("onts", "ont"),
    std::make_pair("ónts", "ónt"),
    std::make_pair("ā", "a"),
    std::make_pair("ā́", "á"),
    std::make_pair("ē", "e"),
    std::make_pair("ḗ", "é"),
    std::make_pair("ī", "i"),
    std::make_pair("ī́", "í"),
    std::make_pair("ō", "o"),
    std::make_pair("ṓ", "ó"),
    std::make_pair("ū", "u"),
    std::make_pair("ū́", "ú"),
    std::make_pair("ey", "i"),
    std::make_pair("éy", "í"),
    std::make_pair("oy", "i"),
    std::make_pair("óy", "í"),
    std::make_pair("ew", "u"),
    std::make_pair("éw", "ú"),
    std::make_pair("ow", "u"),
    std::make_pair("ów", "ú"),
    std::make_pair("wu", "u"),
    std::make_pair("wú", "ú"),
    std::make_pair("eh₂", "a"),
    std::make_pair("éh₂", "á"),
    std::make_pair("eh₃", "o"),
    std::make_pair("éh₃", "ó"),
    std::make_pair("h₂e", "a"),
    std::make_pair("h₂é", "á"),
    std::make_pair("h₃e", "o"),
    std::make_pair("h₃é", "ó"),
    std::make_pair("h₁", ""),
    std::make_pair("h₂", ""),
    std::make_pair("h₃", ""),
    std::make_pair("h₄", ""),
    std::make_pair("H", ""),
    std::make_pair("()", ""),
    std::make_pair("⁽", ""),
    std::make_pair("⁾", "")
};
