#include <iostream>
#include <vector>

using namespace std;

struct table
{
    int no_of_rows;
    struct table *symbolic_link;
};

table *traverseSymbolicLinks(table source_table)
{
    if (source_table.symbolic_link->symbolic_link == NULL)
    {
        return source_table.symbolic_link;
    }
    else
    {
        return traverseSymbolicLinks(*source_table.symbolic_link);
    }
}

int main()
{
    int no_of_tables = 0, no_of_merge_requests = 0, iterator = 0;
    int max_row = 0;

    cin >> no_of_tables >> no_of_merge_requests;

    vector<table> table_data(no_of_tables);
    vector<int> destination(no_of_merge_requests);
    vector<int> source(no_of_merge_requests);
    vector<int> output(no_of_merge_requests);

    for (iterator = 0; iterator < no_of_tables; iterator++)
    {
        cin >> table_data[iterator].no_of_rows;
        table_data[iterator].symbolic_link = NULL;

        if (max_row < table_data[iterator].no_of_rows)
        {
            max_row = table_data[iterator].no_of_rows;
        }
    }

    for (iterator = 0; iterator < no_of_merge_requests; iterator++)
    {
        cin >> destination[iterator] >> source[iterator];
    }

    for (iterator = 0; iterator < no_of_merge_requests; iterator++)
    {
        int current_destination = destination[iterator] - 1;
        int current_source = source[iterator] - 1;
        if (current_destination == current_source)
        {
            cout << max_row << endl;
            continue;
        }

        int source_rows = table_data[current_source].no_of_rows;
        int destination_rows = table_data[current_destination].no_of_rows;

        table *actual_source_table = &table_data[current_source];
        table *actual_destination_table = &table_data[current_destination];

        if (actual_destination_table->symbolic_link != NULL)
        {
            actual_destination_table = traverseSymbolicLinks(*actual_destination_table);
        }
        if (actual_source_table->symbolic_link != NULL)
        {
            actual_source_table = traverseSymbolicLinks(*actual_source_table);
        }
        if (actual_destination_table == actual_source_table)
        {
            cout << max_row << endl;
            continue;
        }

        destination_rows = actual_destination_table->no_of_rows;
        source_rows = actual_source_table->no_of_rows;

        actual_source_table->no_of_rows = 0;
        actual_source_table->symbolic_link = actual_destination_table;

        destination_rows += source_rows;
        actual_destination_table->no_of_rows = destination_rows;

        if (max_row < destination_rows)
        {
            max_row = destination_rows;
        }
        cout << max_row << endl;
    }
    return 0;
}
