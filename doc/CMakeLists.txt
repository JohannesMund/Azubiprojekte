set(DOC_SOURCES
    ${CMAKE_SOURCE_DIR}/doc/Battleship/battleship.md
    ${CMAKE_SOURCE_DIR}/doc/general/templates.md
    ${CMAKE_SOURCE_DIR}/doc/general/iterators.md
    ${CMAKE_SOURCE_DIR}/README.md
)
    
add_custom_target(doc 
	SOURCES ${DOC_SOURCES}
)
