## My Casual Repo

This repository is just an collection of my trail code while learning C++ primer. It also helps me familarize with the git usages. 

So, noted that this repo does **not make any sense**. It is just my own playground.

### 1. How to Upload it to GitHub

Initially, I already have some cpp files locally. Now, I want to creat a github repo and put everyting up-to-date on it. Can we do that just using shell?

I find the solution from this [githubdocs](https://docs.github.com/en/get-started/importing-your-projects-to-github/importing-source-code-to-github/adding-locally-hosted-code-to-github?platform=mac). It suggestes us do it with [Github CLI](), which enables us use command line to control our repo on Github. At first, we need to initialize the local directory as a Git repository:

```bash
git init -b main
```

After this command, one `.git` folder will be created under the curent folder. Then, stage and commit all the files in our project with:

```bash
git add . && git commit -m "initial commit"
```

To create a repository for your project on GitHub, use the `gh repo create` subcommand. When prompted, select **Push an existing local repository to GitHub** and enter the desired name for your repository. 

![image-20221122144134656](https://cdn.jsdelivr.net/gh/Steven-cpp/myPhotoSet@master/img/image-20221122144134656.png)

Now, we have successfully created a Github repo based on our working directory.

### 2. Play with Branches

Initially, I am confused with the git concepts and lingos, such as `master`, `origin`, `remote`. Now, I start to understand that *master* is the <u>branch</u>, which     usually serves as a main branch, and *origin* is the alias of the remote host, which can be monitored by  `git remote -v`. With this command, we can know the exact host where we fetch the online code in the current branch from, and push our code to.

For example, if we want to add a remote from Paul, with the url `https://github.com/paulboone/ticgit` and fetch the code from this new remote:

```bash
$ git remote
origin
$ git remote add pb https://github.com/paulboone/ticgit
$ git remote -v
origin	https://github.com/schacon/ticgit (fetch)
origin	https://github.com/schacon/ticgit (push)
pb	https://github.com/paulboone/ticgit (fetch)
pb	https://github.com/paulboone/ticgit (push)
```

Now we can use the string `pb` on the command line, standing for the whole URL. For example, if you want to fetch all the information that Paul has but that you don't yet have in your repository, you can run `git fetch pb`:

```bash
$ git fetch pb
remote: Counting objects: 43, done.
remote: Compressing objects: 100% (36/36), done.
remote: Total 43 (delta 10), reused 31 (delta 5)
Unpacking objects: 100% (43/43), done.
From https://github.com/paulboone/ticgit
 * [new branch]      master     -> pb/master
 * [new branch]      ticgit     -> pb/ticgit
```

Paul’s `master` branch is now accessible locally as `pb/master` — you can merge it into one of your branches, or you can check out a local branch at that point if you want to inspect it.

From then on, it has been a little bit tricky. Because it leads to `merge`, `checkout` and some other concepts. But they are all centered around branches. So, that is why I want to play with branches in this section.

#### 1) Requirements

This repo is mainly for three different tasks:

1. cpp primer trail;
2. labuladong algorithm;
3. csapp labs

So, I might as well create three different braches corresponding to these tasks, practicing usage of branches of github. And I am required to conduct the task under the specific branch.

#### 2) Usages

Firstly, I need to create branch named `cpp-trail`:

```bash
git brach cpp-trail
```

Then, stage the modifications and upload it to the remote:

```bash
$ git commit -m "add branch"
$ git push -u origin cpp-trail
Enumerating objects: 7, done.
Counting objects: 100% (7/7), done.
Delta compression using up to 8 threads
Compressing objects: 100% (4/4), done.
Writing objects: 100% (4/4), 2.00 KiB | 2.00 MiB/s, done.
Total 4 (delta 2), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
remote: 
remote: Create a pull request for 'cpp-trail' on GitHub by visiting:
remote:      https://github.com/Steven-cpp/MyCasualRepo/pull/new/cpp-trail
remote: 
To https://github.com/Steven-cpp/MyCasualRepo.git
 * [new branch]      cpp-trail -> cpp-trail
Branch 'cpp-trail' set up to track remote branch 'cpp-trail' from 'origin'.
```

We can see that, this branch has also been created in the remote.



### 3. Containers in cpp

Grasping the STL containers in C++ is of great importance. So I created `/01_containers` for all my practices that play with containers.

In C++, container is divided into *sequential container*, *associative container*, and *container adapters*. There are three container adapters: stack, queue, and priority_queue. Essentially, an adaptor is a mechanism for making one thing act like another. A container adaptor takes an existing container type and makes it act like a different type. For example, the `stack` adaptor takes a sequential container (other than `array` or `forward_list`) and makes it operate as if it were a stack.

By default both `stack` and `queue` are implemented in terms of `deque`, and a `priority_queue` is implemented on a `vector`. We can override the default container type by naming a sequential container as a second type argument when we create the adaptor:

```cpp
// empty stack implemented on top of vector 
stack<string, vector<string>> str_stk; 
// str_stk2 is implemented on top of vector and initially holds a copy of svec 
stack<string, vector<string>> str_stk2(svec);
```

For the most part, the containers deﬁne surprisingly few operations, only including construct, add & remove elements, return specific iterators. Other useful operations, such as **sorting or searching, are deﬁned not by the container types but by the standard algorithms**.

#### 1) Memory Mangement

All the containers (except array) provide efﬁcient dynamic memory management. We may add elements to the container without worrying about where to store the elements. The container itself manages its storage. Both `vector` and `string` provide more detailed control over memory management through their `reserve` and `capacity` members.













