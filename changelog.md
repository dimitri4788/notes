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

####Sources
http://keepachangelog.com/  
