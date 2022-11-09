include conf.mk

TARGET      = libeos_polymorphism.a
IFLAGS      = -I./include/

BUILD_DIR   = build

OBJ =  \
eos.o


OBJ_D       = $(patsubst %,$(BUILD_DIR)/%,$(OBJ))

dir_guard=@mkdir -p $(@D)



default: $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

.PHONY: clean

$(BUILD_DIR)/%.o:          src/%.cpp
	$(CXX) $(CXXFLAGS) $(IFLAGS) $(DFLAGS) $(LFLAGS)-c -o $@ $<

$(TARGET): $(BUILD_DIR) $(OBJ_D)
	$(dir_guard)
	$(ARCH) $(ARCHFLAGS) $(TARGET) $(OBJ_D)
	$(RANLIB) $(TARGET)


clean:
	rm -rf $(TARGET) $(OBJ_D)
