# Monorepo or Submodules

## Context
After the WarmUp the team was responsible for deciding how they'd approach the next projects relatively to the repositories structure.  
The question imposed was "Monorepo or Submodules?".  
After some research the team was able to make a comparison between the two methods and choose one of them.  
  
[MONOREPO]  
Pros:  
- easier to manage and track  
- simpler to organize Sprints and Backlog  
- easier to create and manage issues  
  
Cons:  
- branch complexity improves significantly  
- bigger compilation times  
- more difficult to expand  
  
  
[SUBMODULES]  
Pros:  
- better overall organization of the project  
- easier to implement/update dependencies  
  
Cons:  
- repos overload  
- copying all the repository settings each time a new repo is created  

## Decision
After a deeper consideration and debate the team concluded that the monorepo's pros are also appliable to the submodules and decided that a system of submodules linked to a main repository is the best way to manage a big project with multiple dependencies.  
Following this document, an issue will be open regarding the creation of the submodules repositories system.  
The team will have a main repo where all the submodules will be linked to.  
For each Project a new repo will be created and linked to that main repo as a submodule.  
Each submodule will have it's own Backlog, Sprints, branches and issues.  

## Consequences
The submodules method will allow us to better organize our future projects and manage the feature's implementation/adaptation more easily.
