include conf.mk

TARGET      = ./example_eos_polymorphism
IFLAGS      += -I../eos/include

LFLAGS_BASE	+= -L../eos/
LFLAGS_MT  	= $(LFLAGS_BASE) -leos_polymorphism


default: $(TARGET)

$(TARGET): example_eos_polymorphism.cpp
	$(CXX) $(CXXFLAGS) $(OMP_FLAG) $(IFLAGS) $(LFLAGS_MT) -o example_eos_polymorphism $<

clean:
	rm -rf $(TARGET)

clean_target:
	rm -rf $(TARGET)
