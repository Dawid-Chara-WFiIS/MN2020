# Makefile 
# Maciej Woloszyn (c) 2019-10-04


##------------ configuration -- begin ------------------------

# sending files:

PUBKEY := /home/staff/malarz/SWOS/file_upload_key.pub
DEST := /home/staff/malarz/SWOS/Upload

LIST := $(wildcard *.c *.h *.f *.f77 *.for *.png *.eps *.bmp *.gnu *.txt *.dat Makefile)

DATE := $(shell date +%Y%m%dT%H%M%S)
USER := $(shell whoami)
PROJ := MN
BNAME := $(PROJ)_$(USER)_$(DATE)

FILETGZ := $(BNAME).tgz
FILEENC := $(BNAME).enc
RNDKEY := $(BNAME).key
RNDENC := $(BNAME).enk

# compilation and execution:

PROG := lab
CXXFLAGS :=  -MMD -MP -std=c++11 -Wall -Wextra -Wconversion -W
CXX := g++
RM := rm -f
SRC = $(wildcard *.cpp)
OBJECTS = $(SRC:%.cpp=%.o)

##------------ configuration -- end --------------------------

all : $(PROG)

$(PROG) : $(OBJECTS)
	$(CXX) $(OBJECTS) $(CXXLINKLIBS) -o $(PROG)

# include automatically generated dependencies:
-include $(SRC:%.cpp=%.d)

myfiles :
	@ls -R $(DEST) | grep $(USER) | grep enc | sed 's/\.enc/\.tgz/g'

send :
	@tar cvzf $(FILETGZ) $(LIST)
	@openssl rand -base64 -out $(RNDKEY) 32
	@openssl rsautl -encrypt -inkey $(PUBKEY) -pubin -in $(RNDKEY) -out $(RNDENC)
	@openssl enc -aes-256-cbc -pbkdf2 -salt -in $(FILETGZ) -out $(FILEENC) -pass file:./$(RNDKEY)
	@chmod 1644 $(FILEENC) $(RNDENC)
	@cp -a $(FILEENC) $(RNDENC) $(DEST)
	@echo " *** File $(FILETGZ) was sent. *** "
	@$(RM) $(RNDKEY) $(RNDENC) $(FILEENC)

tgz :
	tar cvzf $(FILETGZ) $(LIST)

clean:
	$(RM) *.o *.d

cleanall:
	$(RM) *~ *.o *.d $(PROG)

# end
