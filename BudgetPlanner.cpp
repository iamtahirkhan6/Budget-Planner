#include "BudgetPlanner.hpp"

bool BudgetPlanner::IsMonthInBudgetPlanner(string monthName)
{
    bool found = false;

    for (decltype(months.size()) i = 0; i < months.size(); i++)
    {
        if (months.at(i).GetName() == monthName)
        {
            found = true;
            break;
        }
    }

    return found;
}

void BudgetPlanner::AddMonth(string monthName)
{
    if (!IsMonthInBudgetPlanner(monthName)) 
    {
        Month newMonth = Month(monthName);
        months.push_back(newMonth);
    }
}

int BudgetPlanner::AccessMonth(string monthName)
{
    if (IsMonthInBudgetPlanner(monthName))
    {
        for (decltype(months.size()) i = 0; i < months.size(); i++)
        {
            if (months.at(i).GetName() == monthName)
            {
                return i;
            }
        }
    }
    else
        cout << "Month not found!" << endl;
}

void BudgetPlanner::PrintBudgetPlanner()
{
    float totalBalance = 0;

    for (decltype(months.size()) i = 0; i < months.size(); i++)
    {
        cout << "Month: " << months.at(i).GetName() << "\t\tBudget: " << months.at(i).GetMonthlyBalance() << endl;
        totalBalance += months.at(i).GetMonthlyBalance();
    }

    cout << endl << "Total Balance: " << totalBalance << endl;
}

bool BudgetPlanner::ReadDocument(std::string fileName, std::vector<std::string>& vecOfStrs)
{
    // Open the File
    std::ifstream in(fileName.c_str());
    // Check if object is valid
    if (!in)
    {
        std::cerr << "Cannot open the File : " << fileName << std::endl;
        return false;
    }
    std::string str;
    // Read the next line from File untill it reaches the end.
    while (std::getline(in, str))
    {
        // Line contains string of length > 0 then save it in vector
        if (str.size() > 0)
            vecOfStrs.push_back(str);
    }
    //Close The File
    in.close();
    return true;
}

void BudgetPlanner::WriteDocument(std::vector<std::string>& vecOfStrs) {
    //cout<<"write";
    std::ofstream file;
    file.open("D://SRH//AdvProg//Task4//BudgetPlanner//BudgetPlanner//budget1.txt");
    std::ofstream file_out("D://SRH//AdvProg//Task4//BudgetPlanner//BudgetPlanner//budget1.txt");
    for (const auto& s : vecOfStrs)
    {
        file_out << s << std::endl;
    }
    file.close();
}

void BudgetPlanner::SplitString(std::vector<std::string>& vecOfStr, std::vector<std::string>& v) {
    for (std::string& line : vecOfStr) {
        std::string temp = "";
        std::string s = line;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ' ') {
                v.push_back(temp);
                temp = "";
            }
            else {
                temp.push_back(s[i]);
            }
        }
        //v.push_back(" ");
        v.push_back(temp);
    }
}