APP = MPSProject
SOURCES = main.swift
SDK = $(shell xcrun --sdk macosx --show-sdk-path)

$(APP): $(SOURCES)
	swiftc -o $(APP) $(SOURCES) -sdk $(SDK)

clean:
	rm -f $(APP)
