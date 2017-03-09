---
title: Git 101 @ 30 mins.
separator: \n---\n
verticalSeparator: \n----\n
theme: league
<!--theme: sky-->
revealOptions:
    transition: 'fade'
---

<h1 style="font-size: 72px">
	Git 101 @ 30 mins.
</h1>
<br />

JunYuan Yan

<div align="right">
  <font size="3">
forked from [Git , Denny Huang ](http://denny.one/git-slide)
  </font>
</div>

----

# About me

* i-cube Lab @ NUU
* R&D @ [BotPartner.me](http://www.botpartner.me)
* contact me : jyyan.tw@gmail.com
* [blog](http://blog.jyyan.info) , jyyan @ [github](http://github.com/jyyan)

---

# Why Git
Think different !

----

# 版本控制類型

----

### 本地端版本控制

<div align="center">
  <br />
  <img style="height:500px; width:660px" src="./img/18333fig0101-tn.png" />
</div>

----

### 集中式版本控制系統

<div align="center">
  <br />
  <img style="height:500px; width:660px" src="./img/18333fig0102-tn.png" />
</div>

----

### 分散式版本控制系統

<div align="center">
  <img style="height:500px; width:660px" src="./img/18333fig0103-tn.png" />
</div>

----

<div align="center">
  <img height="500" src="./img/local-remote.png" />
</div>
<div align="right">
  <font size="4">
	<a href="http://zoomq.qiniudn.com/ZQScrapBook/ZqFLOSS/data/20081210180347/" target="_blank">圖片來源</a>
  </font>
</div>

---

### 事前準備

* 註冊 [GitHub](http://github.com) 帳號
* 確認已安裝 Git
    * [Git for windows](https://git-for-windows.github.io/)
	* 在 Terminal 輸入 `git` 確認
	* `sudo apt install git`
	* `sudo dnf install git`
* 選擇編輯器 (vim, emacs, gedit)

----

### 環境設定 - 個人資料 / 偏好設定
```
git config --global user.email "you@example.com"

git config --global user.name "Your Name"

git config --global color.ui true

#換為你慣用的文字編輯器
git config --global core.editor vim
```

----

### 環境設定 - 設定別名

```
git config --global alias.co checkout

git config --global alias.br branch

git config --global alias.ci commit

git config --global alias.st status

git config --global alias.lg "log --color --graph --all --pretty=format:'%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset' --abbrev-commit --"
```

----

# config
.gitconfig

Why `--global`?

```
cat ~/.gitconfig
[user]
	name = JunYuan Yan
	email = jyyan.tw@gmail.com
[color]
	ui = true
```
[config_example.sh](example/config_example.sh)

---

# Practice

Create a new repo on GitHub

----

# 公開 / 私有
Public / Private
<div align="center">
  <a href="https://education.github.com/pack" target="_blank">Student Developer Pack</a>
</div>

----

# 說明文件
README.md
<div align="center">
  <a href="https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet" target="_blank">Markdown Cheatsheet</a>
  <a href="https://guides.github.com/features/mastering-markdown/" target="_blank">Mastering Markdown</a>
</div>

----

# 設定不監控的文件
.gitignore
<div align="center">
  <a href="https://github.com/github/gitignore" target="_blank">collection of useful .gitignore templates</a><br />
  <a href="https://git-lfs.github.com/" target="_blank">Git Large File Storage</a>
</div>

----

# License
<div align="center">
  <a href="http://www.openfoundry.org/tw/licenses" target="_blank">授權條款介紹 - OpenFoundry</a>
</div>

---

# Practice
Delete the repository

---

# Practice
Create an new repo without initialization

---

# Practice
Create a new local repository

----

<h1 style="font-size: 72px">
  <code>git help &lt;command&gt;</code>
</command>

----

# init
```
git init
````

---

# Practice
Add file to staging area

----

<div align="center">
  <img src="./img/index1@2x.png" />
</div>
<div align="right">
  <font size="4">
	<a href="http://git-scm.com/about/staging-area" target="_blank">圖片來源</a>
  </font>
</div>

----

# create README file

```
touch README.md
```

----

# how are you?

```
git status
```

----

### Add file to staging area
```
git add README.md

# will stage all unstage files
# Don't do this...
git add .
```

----

# keep
.gitkeep

----

### Unstage file

```
git reset <file>
```

---

# Practice
### Commit to repository

----

### Before commit

```
git status

#未監控的檔案
git diff

#已監控的檔案
git diff --cached
```

----

### Commit

* `git commit`

* `git commit -m "first commit"`

----

# 何時該 commit？

----

<h1 style="font-size: 72px">
  commit log 怎麼寫？
</h1>
<div align="center">
  <a style="font-size: 30px" href="./img/yo.png" target="_blank">yo</a>
</div>
<div align="right">
  <a style="font-size: 15px" href="http://www.reddit.com/r/shittyprogramming/comments/1skq3s/my_buddy_is_a_phenomenal_programmer_but_really/" target="_blank">圖片來源</a>
</div>

----

# DON'T ...
```
# -a, --all
#   Tell the command to automatically stage files
#   that have been modified and deleted, but
#   new files you have not told Git about are not affected.

git commit -a
```

----

<div align="center">
  <img src="./img/index2@2x.png" />
</div>
<div align="right">
  <font size="4">
	<a href="http://git-scm.com/about/staging-area" target="_blank">圖片來源</a>
  </font>
</div>

---

# Practice
Show commit message

----

### Show commit log

* `git log`

* `git show <revisions>`

----

##  SPECIFYING REVISIONS

```
<sha1>, e.g. dae86e1950b1277e545cee180551750029cfe735, dae86e
<refname>, e.g. master, heads/master, refs/heads/master
<refname>@{<date>}, e.g. master@{yesterday}, HEAD@{5 minutes ago}
```

<div align="center">
  <a href="https://www.kernel.org/pub/software/scm/git/docs/gitrevisions.html" target="_blank">gitrevisions(7) Manual Page</a>
</div>

---

# Practice
Untrack / Rename file

----


Remove file
  ```
  git rm <file>
  ```
Untrack file
  ```
  git rm --cached <file>
  ```
Rename file
  ```
  git mv <file>
  ```

---

# Practice
Back to the past

生命不能重來，但 Git 可以

----

Checkout to previous version

```
git checkout <revision>
```

Checkout file from previous version

```
git checkout <revision> <file>
```

----

### Stash files
```
git stash

git stash save "message"

git stash list

git stash pop

git stash show -p <revision>
```
[ref Stashing](https://git-scm.com/book/zh-tw/v1/Git-%E5%B7%A5%E5%85%B7-%E5%84%B2%E8%97%8F-Stashing)
----

### Reset to previous version

```
git reset <revision>

git reset --hard <revision>
```
[ref rebase -i, reset, revert](https://blog.yorkxin.org/2011/07/29/git-rebase)

----

### Revert commit

```
git revert <revision>
```
[ref rebase -i, reset, revert](https://blog.yorkxin.org/2011/07/29/git-rebase)

----

### Remove untracked files

* `git clean -f`

* `git clean -d`

---

# Practice
Push to remote server

----

### Add remote repo

* `git remote add origin https://github.com/denny0223/workshop.git`

* `git remote`

* `git remote -v`

* `git remote show origin`

----

<div align="center">
  <img height="500" src="./img/local-remote.png" />
</div>
<div align="right">
  <font size="4">
	<a href="http://zoomq.qiniudn.com/ZQScrapBook/ZqFLOSS/data/20081210180347/" target="_blank">圖片來源</a>
  </font>
</div>

----

### List branches

* `git branch`

* `git branch -a`

* `git branch -v`

* `git branch -vv`

----

### Push to remote repo

* `git push -u origin master`

* `git push origin master`

* `git push`

* <a href="http://stackoverflow.com/a/13148313" target="_blank">push.default</a>

----

### Cache https password

`git config --global credential.helper cache`

`git config --global credential.helper "cache --timeout=3600"`

<br />
<div align="right">
<a href="http://stackoverflow.com/questions/5343068/is-there-a-way-to-skip-password-typing-when-using-https-github/5343146#5343146">more</a>
</div>

---

# Practice
Clone your repo via ssh
try to commit and push

----

# `git clone`

----

Please make sure you have the correct access rights
and the repository exists.

----

<h1 style="font-size: 75px">
  <a href="https://help.github.com/articles/generating-ssh-keys" target="_blank">Generating SSH keys</a>
</h1>

---

# Practice
Pull from remote repo
Add a new commit at remote via https repo.

----

# PULL

```
# git fetch + git merge
git pull

# git fetch + git merge + git rebase <remote> <branch>
git pull --rebase <remote name> <branch name>
```
### ref:
* [pull rebase](https://ihower.tw/blog/archives/3843)
* [pull with rebase](http://gitready.com/advanced/2009/02/11/pull-with-rebase.html)

---

# Practice
Resolving conflict

----

<h1 style="font-size: 72px">
  <code>git mergetool</code>
</h1>

----

# Branch

----

<div align="center">
  <img style="width:450px" src="./img/git_branching_model.png" />
</div>

----

<a href="http://pages.github.com/" target="_blank">
  <h1>GitHub Pages</h1>
</a>

----

# Practice
Create a branch

----

Create a branch

* `git branch <branch name>`

* `git checkout -b <branch name>`

---

# Practice
commit and push new branch to remote

----

### Push when local and remote branch name difference

* `git push <remote> <local_branch_name>:<remote_branch_name>`

----

# Git Flow
<h2>
  <a href="http://nvie.com/posts/a-successful-git-branching-model/" target="_blank">A successful Git branching model</a>
</h2>

----

<div align="center">
  <img style="width:450px" src="./img/git_branching_model.png" />
</div>

---

# Practice
merge branches

----

### Merge

* `git merge <branch>`

* `git merge --no-ff <branch>`

---

# Practice
Delete branches

----

Delete branch

* `git branch -d <branch>`

* `git branch -D <branch>`

* `git push <remote> :<branch>`

* `git fetch -p`

----

Move branch refs

* `git branch -f <branch>`

* `git branch -f <branch> <revision>`

---

# Practice
Trace log

----

### More about diff

* `git diff <revision>`

* `git diff master@{2014-07-01}`

* `git diff master@{"1 month ago"}`

----

### More about git log

* `git log -p --stat`

* `git log --oneline`

* `git log --graph`

* `git log --abbrev-commit`

* `git log --pretty=%an`

* `git whatchanged`

----

### Limit

* `git log --author="Denny Huang"`

* `git log --since={2014-07-01} --until="1 week ago"`

### search by regex

* `git log -p -i -G 'regex'`

----

### Who wrote this code?

* `git blame <filepath>`

----

### Tag

* `git tag <tagname>`

* `git push <remote> <tagname>`

* `git tag -d <tagname>`

* `git push <remote> :<tagname>`

* <a href="https://help.github.com/categories/releases/" target="_blank">Release on GitHub</a>

----

### Rebase

接枝技

* `git rebase`
[ref rebase -i, reset, revert](https://blog.yorkxin.org/2011/07/29/git-rebase)

----

### Cherry-pick

* `git cherry-pick <revision>`

----

### Patch file

* `git format-patch`

* `git am <patch_file>`

----

### Submodule

* `git submodule add <repo>`

* `git submodule init`

* `git submodule update`

* `git submodule foreach git pull origin master`

----

### Patch commit

* `git add --patch`

* `git commit --patch`

---

# Practice
Modify you commit

----

### Modify commit history

* `git commit --amend`

* `git commit --amend --date="Mar 15 00:00 2014"`

* `git rebase -i <revision>`

----

### Useful skill

* `git reflog`

* `git fsck`

---

### Hosting a Git server

* bare repo

* <a href="http://gogs.io/" target="_blank">Gogs</a>

* <a href="https://about.gitlab.com/" target="_blank">GitLab</a>

---

# Issue tracking system

---

# Continuous Integration (CI)

---

<h1 style="font-size: 68px">
  剩下就是你們的事了
</h1>

---

### Something useful

* <a href="http://pages.github.com/" target="_blank">GitHub Pages</a>

* <a href="https://github.com/k4rthik/git-cal" target="_blank">git-cal</a>

* <a href="http://pcottle.github.io/learnGitBranching/" target="_blank">Learn Git Branching</a>

* <a href="https://github.com/JuanitoFatas/git-style-guide/blob/master/README.md" target="_blank">git-style-guide</a>

----

### Something useful (cnt.

* <a href="https://guides.github.com/" target="_blank">GitHub Guides</a>

* <a href="https://github.com/jlord/git-it/blob/master/README-zhtw.md" target="_blank">Git-it</a>

* <a href="http://onlywei.github.io/explain-git-with-d3/" target="_blank">Visualizing Git Concepts with D3</a>

### Just for fun

* <a href="https://github.com/gelstudios/gitfiti" target="_blank">gitfiti</a>

----

### Resources

* <a href="http://git-scm.com/book" target="_blank">Pro Git</a>

* <a href="http://git-scm.com/book/zh-tw" target="_blank">Pro Git (zh-tw)</a>

* <a href="http://ihower.tw/git/" target="_blank">版本控制系統 Git 精要</a>

* <a href="http://www-cs-students.stanford.edu/~blynn/gitmagic/intl/zh_tw/" target="_blank">Git Magic</a>

----

### Resources (cnt.

* <a href="http://backlogtool.com/git-guide/en/" target="_blank">Git Beginner&#39;s Guide for Dummies</a>

* <a href="http://backlogtool.com/git-guide//tw/" target="_blank">連猴子都能懂的Git入門〜掌握版本控制〜</a>

* <a href="http://www.slideshare.net/ihower/git-40877359" target="_blank">Git 版本控制系統 --- 從微觀到宏觀</a>

----

## 10 year

* <a href="https://www.atlassian.com/git/articles/10-years-of-git/" target="_blank">10 Years of Git</a>

* <a href="http://ithome.com.tw/news/95088" target="_blank">Git 十歲了！Git 之父 Linus Torvalds 說古，大談 Git 的起源</a>

---

<h1 style="font-size: 72px">
  Thanks for listening!
</h1>

<br /><br /><br />
<div align="center">
  <img style="width:100px;" src="./img/by-sa.png" />
</div>
<h2 style="font-size: 18px">
本投影片採用<a href="http://creativecommons.org/licenses/by-sa/3.0/tw/" target="_blank">創用 CC「姓名標示—相同方式分享 3.0 台灣」授權條款</a>
</h2>

