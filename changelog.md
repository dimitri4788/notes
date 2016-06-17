###CHANGELOG
A change log is a file which contains a curated, chronologically ordered list of notable changes for each version of a project.  

####What makes a good change log?
A good change log sticks to these principles:  
- It’s made for humans, not machines, so legibility is crucial.
- Easy to link to any section (hence Markdown over plain text).
- One sub-section per version.
- List releases in reverse-chronological order (newest on top).
- Write all dates in YYYY-MM-DD format. (Example: 2012-06-02 for June 2nd, 2012.) It’s international, sensible, and language-independent.
- Explicitly mention whether the project follows Semantic Versioning.
- Each version should:
    - List its release date in the above format.
    - Group changes to describe their impact on the project, as follows:
        - **Added** for new features.
        - **Changed** for changes in existing functionality.
        - **Deprecated** for once-stable features removed in upcoming releases.
        - **Removed** for deprecated features removed in this release.
        - **Fixed** for any bug fixes.
        - **Security** to invite users to upgrade in case of vulnerabilities.

####How can I minimize the effort required?  
Always have an "Unreleased" section at the top for keeping track of any changes.  
This serves two purposes:  
- People can see what changes they might expect in upcoming releases
- At release time, you just have to change "Unreleased" to the version number and add a new "Unreleased" header at the top.


#####What about yanked releases?
Yanked releases are versions that had to be pulled because of a serious bug or security issue. Often these versions don't even appear in change logs. They should. This is how you should display them:  
`## 0.0.5 - 2014-12-13 [YANKED]`  
The [YANKED] tag is loud for a reason. It's important for people to notice it. Since it's surrounded by brackets it's also easier to parse programmatically.

####Sources
- http://keepachangelog.com/  
- https://github.com/olivierlacan/keep-a-changelog/blob/master/CHANGELOG.md
