#Makefile generique
#Outils
CXX=g++
LD=g++
RM=rm
ECHO=echo

#Options
CXXFLAGS= -g -W -Wall -pedantic -Wextra -ansi -O2 -std=c++11 -DMAP
LDFLAGS=
RMFLAGS=-rf

#Fichiers
HEAD=$(wildcard *.h)
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
LIBS=

#Cibles speciales
EXE=trajet
RUN=execute
CLEAN=clean
.PHONY: $(CLEAN) $(RUN)

#Cibles
$(EXE): $(OBJ)
	@$(ECHO) Edition des liens
	@$(LD) $(LDFLAGS) $^ -o $@ $(LIBS)

$(RUN): $(EXE)
	@$(ECHO) Execution de $^
	@./$(EXE)

$(CLEAN):
	@$(RM) $(RMFLAGS) $(EXE) $(OBJ)

#Dependances complementaires

#Regles d'inference
%.o: %.cpp
	@$(ECHO) Compilation de $<
	@$(CXX) $(CXXFLAGS) -c $< -o $@
