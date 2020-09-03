#include "calculator.h"

calculator::calculator() {
    num.clear();
    opera.clear();
    p.clear();

}
calculator::~calculator() {
    num.clear();
    opera.clear();
    p.clear();

}
void calculator:: Infix_to_suffix(const string& a) {
    for (int i = 0; i <int(a.size()) ; i++) {
        if (a[i] == '-') {
            if (i == 0) {
                i++;
                char tem_num1[250];
                int j = 0;
                double tem_num = 0;
                while ((a[i] >= '0' && a[i] <= '9') || a[i] == '.') {
                    tem_num1[j] = a[i];
                    j++;
                    i++;
                }
                tem_num1[j] = '\0';
                tem_num = atof(tem_num1);
                my_struct uu;
                uu.ch = '\0';
                uu.type = 0;
                uu.num = -tem_num;
                p.push(uu);
                i--;

            }
            else if ((a[i - 1] < '0' || a[i - 1] > '9') && a[i - 1] != ')') {

                i++;
                char tem_num1[250];
                int j = 0;
                double tem_num = 0;
                while ((a[i] >= '0' && a[i] <= '9') || a[i] == '.') {
                    tem_num1[j] = a[i];
                    j++;
                    i++;
                }
                tem_num1[j] = '\0';
                tem_num = atof(tem_num1);
                my_struct uu;
                uu.ch = '\0';
                uu.type = 0;
                uu.num = -tem_num;
                p.push(uu);
                i--;
            }
            else {
                my_struct uu;
                uu.type = 1;
                uu.num = 0;
                char topch;
                topch = opera.getTop();
                if (topch == '*' || topch == '/' || topch == '-' || topch == '+') {
                    opera.pop();
                    uu.ch = topch;
                    p.push(uu);
                    i--;
                }
                else {
                    opera.push(a[i]);

                }

            }

        }

        else if (a[i] == '+' || a[i] == '*' || a[i] == '(' || a[i] == ')' || a[i] == '/') {
            my_struct uu;
            uu.type = 1;
            uu.num = 0;
            char topch;
            switch (a[i]) {
            case '(':
                opera.push(a[i]);
                break;
            case '+':
                if (opera.empty()) {
                    opera.push(a[i]);
                }
                else {
                    topch = opera.getTop();
                    if (topch == '*' || topch == '/' || topch == '+' || topch == '-') {
                        opera.pop();
                        uu.ch = topch;
                        p.push(uu);
                        i--;
                    }
                    else {
                        opera.push(a[i]);

                    }

                }

                break;

            case '*':


                if (opera.empty()) {
                    opera.push(a[i]);
                }
                else {
                    topch = opera.getTop();
                    if (topch == '*' || topch == '/') {
                        opera.pop();
                        uu.ch = topch;
                        p.push(uu);
                        i--;
                    }
                    else {
                        opera.push(a[i]);

                    }

                }

                break;
            case '/':
                if (opera.empty()) {
                    opera.push(a[i]);
                }
                else {
                    topch = opera.getTop();
                    if (topch == '/' || topch == '*') {
                        opera.pop();
                        uu.ch = topch;
                        p.push(uu);
                        i--;
                    }
                    else {
                        opera.push(a[i]);

                    }

                }
                break;
            case ')':
            {
                while (opera.getTop() != '(') {
                    my_struct o;
                    o.type = 1;
                    o.num = 0;
                    o.ch = opera.getTop();
                    opera.pop();
                    p.push(o);
                }
                opera.pop();
            }

            break;
            }


        }
        else {
            char tem_num1[250];
            int j = 0;
            double tem_num = 0;
            while ((a[i] >= '0' && a[i] <= '9') || a[i] == '.') {
                tem_num1[j] = a[i];
                j++;
                i++;
            }
            tem_num1[j] = '\0';
            tem_num = atof(tem_num1);
            my_struct uu;
            uu.ch = '\0';
            uu.type = 0;
            uu.num = tem_num;
            p.push(uu);
            i--;
        }


    }
    while (opera.empty() != 1) {
        my_struct uu;
        uu.type = 1;
        uu.num = 0;
        uu.ch = opera.pop();
        p.push(uu);
    }

}
double calculator::Suffix_expression_calculation() {
    my_struct uu;
    uu.type = 1;
    uu.num = 0;
    uu.ch = '\0';
    p.push(uu);
    my_Stack<my_struct> pt;

    while (p.empty() == 0) {
        pt.push(p.pop());
    }

    while (pt.empty() == 0) {
        my_struct u;
        u = pt.pop();
        if (u.ch == '\0' && u.type == 1)
            break;
        if (u.type == 0) {
            num.push(u.num);
        }
        else {
            double c=0;
            double t=0;
            switch (u.ch) {
            case '+':
                c = num.pop();
                t = num.pop();
                num.push(c + t);
                break;
            case '-':
                c = num.pop();
                t = num.pop();
                num.push(t - c);
                break;
            case '*':
                c = num.pop();
                t = num.pop();
                num.push(c * t);
                break;
            case '/':
                c = num.pop();
                t = num.pop();
                num.push(t / c);
                break;
            }
        }

    }
    return num.getTop();
}
