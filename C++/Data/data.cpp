#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// Define a structure to represent a rule
struct Rule {
    int priority;
    std::string text;
    std::vector<std::string> requiredVariables;
};

// Define a type for storing rules based on the combination of variables
typedef std::unordered_map<std::string, Rule> RulesMap;

// Define a type for storing rules for different customers
typedef std::unordered_map<int, RulesMap> CustomerRules;

// Function to find the highest priority match for a set of variables
Rule findHighestPriorityMatch(const CustomerRules& customerRules, int customerID, const std::vector<std::string>& variables) {
    auto customerIt = customerRules.find(customerID);
    if (customerIt != customerRules.end()) {
        const RulesMap& rules = customerIt->second;

        // Iterate through rules and find the highest priority match
        Rule highestPriorityMatch{0, "", {}};
        for (const auto& rule : rules) {
            const Rule& currentRule = rule.second;

            // Check if all required variables are present
            if (std::all_of(currentRule.requiredVariables.begin(), currentRule.requiredVariables.end(),
                            [&variables](const std::string& requiredVar) {
                                return std::find(variables.begin(), variables.end(), requiredVar) != variables.end();
                            })) {
                // Update highest priority match if the priority is higher
                if (currentRule.priority > highestPriorityMatch.priority) {
                    highestPriorityMatch = currentRule;
                }
            }
        }

        return highestPriorityMatch;
    }

    // Default case if customer rules are not found
    return {0, "", {}};
}

int main() {
    // Define rules for Customer 1
    CustomerRules customer1Rules;
    customer1Rules[1]["abc"] = {2, "abc", {"Customer", "Country", "Sender"}};
    customer1Rules[1]["bcd"] = {1, "bcd", {"Customer", "VPC"}};
    customer1Rules[1]["zbd"] = {4, "zbd", {"Customer", "Content", "Country", "Sender"}};

    // Define rules for Customer 2
    CustomerRules customer2Rules;
    customer2Rules[2]["abc"] = {7, "abc", {"Customer", "Country", "Sender"}};
    customer2Rules[2]["bcd"] = {12, "bcd", {"Customer", "VPC", "Product"}};
    customer2Rules[2]["zbd"] = {5, "zbd", {"Customer", "Content", "Country", "Sender", "Product", "Content"}};

    // Example variables for Customer 1
    int customerID1 = 1;
    std::vector<std::string> variables1 = {"Customer", "Product", "VPC", "Country", "Sender", "Content"};

    // Example variables for Customer 2
    int customerID2 = 2;
    std::vector<std::string> variables2 = {"Customer", "Product", "VPC", "Country", "Sender", "Content"};

    // Find and print the highest priority match for Customer 1
    Rule match1 = findHighestPriorityMatch(customer1Rules, customerID1, variables1);
    std::cout << "Customer 1 Match: Priority = " << match1.priority << ", Text = " << match1.text << std::endl;

    // Find and print the highest priority match for Customer 2
    Rule match2 = findHighestPriorityMatch(customer2Rules, customerID2, variables2);
    std::cout << "Customer 2 Match: Priority = " << match2.priority << ", Text = " << match2.text << std::endl;

    return 0;
}
