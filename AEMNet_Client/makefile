
# === Conditionals ===================================================================================================

# === Settings =======================================================================================================

CC=gcc
CFLAGS=-c -g -Wall
LINKFLAGS=-g -Wall

# === Include other makefiles ========================================================================================

-include make.functions

# === Compilation settings ===========================================================================================

DEFINE_FLAGS=

# === Source and object file directories =============================================================================

SRC_DIR=./src
BUILD_DIR=./bin
OBJECT_BUILD_DIR=./bin/src

# === Include directories ============================================================================================

INC_DIR=./inc

# === Library files and paths ========================================================================================

# === Consolidating include and library flags ========================================================================

ALL_INC_FLAGS= \
-I$(INC_DIR)

ALL_LIB_FLAGS= \
-lpthread

ALL_LIB_PATH_FLAGS=

LIBDEP=

# === Outputs ========================================================================================================

AEMNET=$(BUILD_DIR)/aemnet

# === Source files ===================================================================================================

SRC_FILES=$(wildcard $(SRC_DIR)/*.c)

ALL_SRC_FILES=$(SRC_FILES)

# === Object files ===================================================================================================

AEMNET_OBJS=$(call source-to-object, $(ALL_SRC_FILES))

# === Consolidation of objects and object files ======================================================================

ALL_OBJS= \
$(AEMNET_OBJS)

ALL_OUTPUTS= \
$(AEMNET)

DEPENDENCIES = $(subst .o,.d,$(ALL_OBJS))

KILL_OBJS=$(wildcard $(OBJECT_BUILD_DIR)/*.o)
KILL_DEPENDENCIES=$(wildcard $(OBJECT_BUILD_DIR)/*.d)

# === Targets ========================================================================================================

.PHONY: all clean debug print_build_settings

all: debug

debug: $(AEMNET)

print_build_settings:

	@echo "ALL_OUTPUTS"
	@echo $(ALL_OUTPUTS)
	
	@echo "ALL_SRC_FILES"
	@echo $(ALL_SRC_FILES)
	
	@echo "ALL_INC_FLAGS"
	@echo $(ALL_INC_FLAGS)
	
	@echo "ALL_OBJS"
	@echo $(ALL_OBJS)

	@echo "DEPENDENCIES"
	@echo $(DEPENDENCIES)
	
	@echo "LIBDEP"
	@echo $(LIBDEP)

	@echo "ALL_LIB_FLAGS"
	@echo $(ALL_LIB_FLAGS)

	@echo "ALL_LIB_PATH_FLAGS"
	@echo $(ALL_LIB_PATH_FLAGS)
	
clean:
	rm -f $(ALL_OBJS)
	rm -f $(DEPENDENCIES)
	rm -f $(ALL_OUTPUTS)
	rm -f $(KILL_OBJS)
	rm -f $(KILL_DEPENDENCIES)

nmlisting:
	nm -S --numeric-sort --print-size --demangle $(AEMNET) > nmlisting.txt

ifneq "$(MAKECMDGOALS)" "clean"
  -include $(DEPENDENCIES)
endif

$(AEMNET): $(AEMNET_OBJS) $(LIBDEP)
	$(call echo-building-binary, $@)
	@mkdir -p $(dir $@)
	$(CC) $(LINKFLAGS) $(ALL_INC_FLAGS) $^ $(ALL_LIB_FLAGS) $(ALL_LIB_PATH_FLAGS) -o $@

# Generic compilation rule
$(OBJECT_BUILD_DIR)/%.c.o: $(SRC_DIR)/%.c
	@$(call echo-building-binary, $@)
	@mkdir -p $(dir $@)
	@echo "Generating dependencies for $<"
	@$(call make-depend,$<,$@,$(subst .o,.d,$@), $(CFLAGS), $(ALL_INC_FLAGS), $(DEFINE_FLAGS))
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) $(ALL_INC_FLAGS) $(DEFINE_FLAGS) -c $< -o $@

# usage: $(call make-depend,source-file,object-file,depend-file,compile-flags,include-flags,define-flags)
define make-depend
  $(CC) -MM          	\
        -MF $3          \
        -MP             \
        -MT $2          \
        $4 $5 $6        \
        $1
endef

