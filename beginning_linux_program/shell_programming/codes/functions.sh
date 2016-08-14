#!/bin/sh

# 
# echo ""
# echo "================================ Simple Function ================================"
# echo ""
# 
# 
# foo () {
#     echo " in foo Function :: !!!!!"
# }
# 
# echo "calling functions"
# foo
# echo "terminating script"

echo ""
echo "================================ local & global variables in functions ================================"
echo ""

# Note that you can declare local variables within shell functions by using the local keyword. The variable is
# then only in scope within the function. Otherwise, the function can access the other shell variables that are
# essentially global in scope. If a local variable has the same name as a global variable, it overlays that variable,
# but only within the function. For example, you can make the following changes to the preceding script to see
# this in action:

sample_text="global variable"
foo() {
    local sample_text="local variable"
    echo "Function foo is executing"
    echo $sample_text
}
echo "script starting"
echo $sample_text

foo 

echo "script ended"
echo $sample_text

exit 0
