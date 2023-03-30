int main() {
    ifstream a("a.txt"); // {1, 3, 5, 7, 9}
    ifstream b("b.txt"); // {11, 15, 3, 99, 1}
    vector<double> alist;
    // read in all the numbers from a into vector alist
    
    vector<double> blist;
    // read in all the numbers from b into vector blist


    // print all elements in blist


    // print out only the numbers that are in both files
    // brute force: O(n^2)
    printcommon(alist, blist);

    // put all elements in a into a set (look it up)
    set<double> aset; {1,3,5,7,9}

    // lookup operation to test if it's in the set

    // for each element in the listb, print if it's in the aset
    printcommon(aset, blist);

    ifstream prez("prez.txt");
    unordered_map<string,string> presidents;
    // read in all the presidents from the file into map

    // print out the map
}