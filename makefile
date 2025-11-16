CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g -Iheaders
SRCDIR = src
OBJDIR = obj
TARGET = game.exe

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir "$(OBJDIR)"

clean:
	@if exist "$(OBJDIR)" rmdir /S /Q "$(OBJDIR)"
	@if exist "$(TARGET)" del "$(TARGET)"

.PHONY: clean