git add *
git status
echo "enter commit msg"
read comm_msg
git commit -m $comm_msg
git push origin master
