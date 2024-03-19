#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

struct Rule {
    int priority;
    std::vector<std::string> customerIDs;
    std::vector<std::string> products;
    std::vector<std::string> senderIDs;
    std::vector<std::string> contents;
    std::vector<std::string> countries;
    std::vector<std::string> VPCs;
};

using RulesTable = std::unordered_map<int, Rule>;

// Function to divide rules into tables based on the presence of CustomerID
void divideRules(const RulesTable& allRules, std::unordered_map<std::string, RulesTable>& customerIDTables, RulesTable& withoutCustomerIDTable) {
    for (const auto& rule : allRules) {
        const Rule& currentRule = rule.second;
        
        if (!currentRule.customerIDs.empty()) {
            for (const auto& customerID : currentRule.customerIDs) {
                customerIDTables[customerID][rule.first] = currentRule;
            }
        } else {
            withoutCustomerIDTable[rule.first] = currentRule;
        }
    }
}

Rule findHighestPriorityMatch(const RulesTable& rulesTable, const std::string& customerID,
                               const std::string& product, const std::string& senderID,
                               const std::string& content, const std::string& country,
                               const std::string& VPC) {
    Rule highestPriorityMatch{0, {}, {}, {}, {}, {}, {}};

    auto checkField = [](const std::vector<std::string>& ruleField, const std::string& inputField) {
        return std::find(ruleField.begin(), ruleField.end(), inputField) != ruleField.end();
    };

    for (const auto& rule : rulesTable) {
        const Rule& currentRule = rule.second;

        if ((checkField(currentRule.customerIDs, customerID) || currentRule.customerIDs.empty()) &&
            (checkField(currentRule.products, product) || currentRule.products.empty()) &&
            (checkField(currentRule.senderIDs, senderID) || currentRule.senderIDs.empty()) &&
            (checkField(currentRule.contents, content) || currentRule.contents.empty()) &&
            (checkField(currentRule.countries, country) || currentRule.countries.empty()) &&
            (checkField(currentRule.VPCs, VPC) || currentRule.VPCs.empty())) {
            if (currentRule.priority > highestPriorityMatch.priority) {
                highestPriorityMatch = currentRule;
            }
        }
    }

    return highestPriorityMatch;
}

int main() {
    // Initialize rules table
    RulesTable rulesTable;
    rulesTable[1] = {1, {"22886-1", "2286-2"}, {"PRD001", "PRD002"}, {"AJAY"}, {"Cancel"}, {"IND", "BZ"}, {"1-1-1", "2-2-2", "3-3-3"}};
    rulesTable[2] = {2, {"22886-1", "2286-2"}, {}, {"AJAY"}, {}, {}, {}};
    rulesTable[3] = {3, {}, {"PRD001", "PRD002"}, {}, {}, {}, {"1-1-1", "2-2-2", "3-3-3"}};
    rulesTable[4] = {4, {}, {"PRD001", "PRD002"}, {}, {}, {"IND", "BZ"}, {}};
    rulesTable[5] = {1, {"22886-3", "2286-4"}, {"PRD003", "PRD004"}, {"AJAY"}, {"Cancel"}, {"IND", "BZ"}, {"1-1-1", "2-2-2", "3-3-3"}};
    rulesTable[6] = {2, {"22886-4", "2286-3"}, {}, {"AJAY"}, {}, {}, {}};
    rulesTable[7] = {3, {}, {"PRD003", "PRD004"}, {}, {}, {}, {"1-1-1", "2-2-2", "3-3-3"}};
    rulesTable[8] = {4, {}, {"PRD003", "PRD004"}, {}, {}, {"IND", "BZ"}, {}};

    // Divide rules into tables based on the presence of CustomerID
    std::unordered_map<std::string, RulesTable> customerIDTables;
    RulesTable withoutCustomerIDTable;
    divideRules(rulesTable, customerIDTables, withoutCustomerIDTable);

    // User input values
    std::string customerID = "2286-1";
    std::string product = "PRD001";
    std::string senderID = "AJAY";
    std::string content = "Hi Cancel";
    std::string country = "IND";
    std::string VPC = "2-2-2";

    // Find and print the highest priority match
    Rule match;
    
    auto checkCustomerIDTable = customerIDTables.find(customerID);
    if (checkCustomerIDTable != customerIDTables.end()) {
        match = findHighestPriorityMatch(checkCustomerIDTable->second, customerID, product, senderID, content, country, VPC);
    } else {
        match = findHighestPriorityMatch(withoutCustomerIDTable, customerID, product, senderID, content, country, VPC);
    }

    if (match.priority > 0) {
        std::cout << "Match: Priority = " << match.priority << ",\nCustomer IDs = ";
        for (const auto& id : match.customerIDs) {
            std::cout << id << " ";
        }
        std::cout << ",\nProducts = ";
        for (const auto& prod : match.products) {
            std::cout << prod << " ";
        }
        std::cout << ",\nSender IDs = ";
        for (const auto& sender : match.senderIDs) {
            std::cout << sender << " ";
        }
        std::cout << ",\nContents = ";
        for (const auto& cont : match.contents) {
            std::cout << cont << " ";
        }
        std::cout << ",\nCountries = ";
        for (const auto& country : match.countries) {
            std::cout << country << " ";
        }
        std::cout << ",\nVPCs = ";
        for (const auto& vpc : match.VPCs) {
            std::cout << vpc << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No data present." << std::endl;
    }

    return 0;
}
