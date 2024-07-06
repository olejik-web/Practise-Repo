package com.git_project;

import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.assertEquals;

import org.apache.commons.lang3.StringUtils;
import org.apache.commons.lang3.ArrayUtils;

import org.junit.jupiter.api.Test;


public class AppTest {
	@Test
	public void shouldAnswerWithTrue() {
		assertTrue(true);
	}
	
	@Test
	public void whenCalledhashCode_thenCorrect() {
		String[] array = {"a", "b", "c"};
		assertEquals(ArrayUtils.hashCode(array), 997619);
	}
}
