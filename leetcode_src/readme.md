## My Casual Repo

This repository is just an collection of my trail code while learning C++ primer. It also helps me familarize with the git usages. 

So, noted that this repo does **not make any sense**. It is just my own playground.

### 1. Learn to Upload it to GitHub

Initially, I already have some cpp files locally. Now, I want to creat a github repo and put everyting up-to-date on it. Can we do that just using shell?

I find the solution from this [githubdocs](https://docs.github.com/en/get-started/importing-your-projects-to-github/importing-source-code-to-github/adding-locally-hosted-code-to-github?platform=mac). It suggestes us do it with Github CLI, which enables us use command line to control our repo on Github. At first, we need to initialize the local directory as a Git repository:

```bash
git init -b main
```

After this command, one `.git` folder will be created under the curent folder. Then, stage and commit all the files in our project with:

```bash
git add . && git commit -m "initial commit"
```

To create a repository for your project on GitHub, use the `gh repo create` subcommand. When prompted, select **Push an existing local repository to GitHub** and enter the desired name for your repository. 