set(DOC_SOURCES
    ${CMAKE_SOURCE_DIR}/doc/battleship.md
    ${CMAKE_SOURCE_DIR}/doc/templates.md
    ${CMAKE_SOURCE_DIR}/doc/iterators.md
    ${CMAKE_SOURCE_DIR}/README.md
)
    
add_custom_target(doc 
	SOURCES ${DOC_SOURCES}
)
