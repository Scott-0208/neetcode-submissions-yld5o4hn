class Solution:
    def get_all_shuffles(self, input_string):
        if len(input_string) <= 1:
            return {input_string}
        shuffles = set()
        for i, char in enumerate(input_string):
            remaining_chars = input_string[:i] + input_string[i+1:]
            for sub_shuffle in self.get_all_shuffles(remaining_chars):
                shuffles.add(char + sub_shuffle)
        return shuffles
    def isAnagram(self, s: str, t: str) -> bool:
        return sorted(s) == sorted(t)
        # s_shuf = self.get_all_shuffles(s)
        # t_shuf = self.get_all_shuffles(t)
        # num_same = 0
        # for i in s_shuf:
        #     for j in t_shuf:
        #         if i == j:
        #             num_same+=1
        #             return True
        # if num_same == 0:
        #     return False