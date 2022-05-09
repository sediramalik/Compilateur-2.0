----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 09.05.2022 11:01:51
-- Design Name: 
-- Module Name: REGISTER_FILE_Test - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity REGISTER_FILE_Test is

end REGISTER_FILE_Test;

architecture Behavioral of REGISTER_FILE_Test is
component REGISTER_FILE
    Port ( aA : in STD_LOGIC_VECTOR (3 downto 0);
           aB : in STD_LOGIC_VECTOR (3 downto 0);
           aW : in STD_LOGIC_VECTOR (3 downto 0);
           W : in STD_LOGIC;
           DATA : in STD_LOGIC_VECTOR (7 downto 0);
           RST : in STD_LOGIC;
           CLK : in STD_LOGIC;
           QA : out STD_LOGIC_VECTOR (7 downto 0);
           QB : out STD_LOGIC_VECTOR (7 downto 0));
end component;

--Inputs
signal aA : STD_LOGIC_VECTOR (3 downto 0) := (others=>'0');
signal aB : STD_LOGIC_VECTOR (3 downto 0) := (others=>'0');
signal aW : STD_LOGIC_VECTOR (3 downto 0) := (others=>'0');
signal W : STD_LOGIC := '0';
signal DATA : STD_LOGIC_VECTOR (7 downto 0) := (others=>'0');
signal RST : STD_LOGIC := '0';
signal CLK : STD_LOGIC := '0';

--Outputs
signal QA : STD_LOGIC_VECTOR (7 downto 0) := (others=>'0');
signal QB : STD_LOGIC_VECTOR (7 downto 0) := (others=>'0');

begin
UUT:  REGISTER_FILE PORT MAP(
aA => aA,
aB => aB,
aW => aW,
W => W,
DATA => DATA,
RST => RST,
CLK => CLK,
QA => QA,
QB => QB
);

--SIMULATE CLOCK
SIM_CLK : process
begin
CLK <= NOT(CLK);
WAIT FOR 5ns;
end process;

process
begin

RST <= '0';
aA <= "0000";
aB <= "0001";
aW <= "0000";
W <= '1';
DATA <= "11111111";
wait for 20ns;

end process;

end Behavioral;
