
// #include <cstdio>
// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>

// using namespace std;


// struct Element {
//   string tag;
//   vector<string> attributes;
//   vector<string> values;
//   vector<Element> content;
//   string text;
// };


// vector<Element> parse (string *md_pointer, int start_index, vector<string> pending_elements);


// int main () {

//   string a = "testing";
//   string *pa = &a;
//   string b = *pa;
//   cout << b << endl;

//   return 0;
//   int short unsigned lines_count, queries_count;
//   scanf("%hu %hu\n", &lines_count, &queries_count);

//   string md = "";
//   for (int short unsigned line_index = 0; line_index < lines_count; line_index++) {
//     string line;
//     getline(cin, line);
//     md.insert(md.length(), line);
//   }

//   vector<Element> elements = parse(md);

//   cin.get();
//   return 0;
// }


// Element create_text (string data) {
//   struct Element element;
//   element.text = data;
//   return element;
// }

// vector<Element> parse (string md) {

//   vector<Element> elements;
//   int index = 0;

//   while (index < md.length()) {

//     // get first tag opening
//     int tag_opening_start = md.find("<");

//     bool has_text = false;

//     // check if no tag
//     if (tag_opening_start != index) {
//       has_text = true;
//       elements.push_back(create_text(md.substr(index, tag_opening_start)));
//     }

//     // get tag opening close
//     int tag_opening_end = md.find(">", tag_opening_start);
//     // check if the tag syntax is invalid
//     if (tag_opening_end == string::npos) {
//       string text = md.substr(tag_opening_start, md.length());
//       // check if there is a previous text element to append current text to
//       if (has_text) {
//         int text_size = elements.at(elements.size() - 1).text.length();
//         elements.at(elements.size() - 1).text.insert(text_size, text);
//       } else {
//         elements.push_back(create_text(text));
//       }
//     }



//     // just for tesing
//     index = md.length();

//   }

//   return elements;
// }