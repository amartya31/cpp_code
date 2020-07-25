# cpp_code
$ git config --global user.name "amartya31"
$ git config --global user.email ghosh.amartya31@gmail.com

#to set up remote and repetative logins 

#TO generate host ket

ssh-keygen -t rsa -b 4096 -C "ghosh.amartya31@gmail.com"
eval $(ssh-agent -s)
ssh-add ~/.ssh/id_rsa
cat ~/.ssh/id_rsa.pub

GO to user setting, then set public key

#TO avoide repetative login

git remote -v
#git remote set-url git@github.com:USERNAME/REPOSITORY.git
git remote set-url origin git@github.com:amartya31/cpp_code.git
